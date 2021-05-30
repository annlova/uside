//
// Created by Anton on 2021-05-26.
//

#include "../h/tokenizer.h"

#include <regex>
#include <charconv>

#include <configs/parser_config.h>
#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>

parser::Tokenizer::Tokenizer(const std::string& parserInfo) : mRules(), mRulesByCategory(), mSymbols(), mSymbolNameToIdMap() DEBUG_CODE(COMMA mSymbolRegexStrings() COMMA mSymbolIdToNameMap()),
                                                              mSourceCode(), mSourceCodeIndex{0}, mLineCommentSymbolId{-1}, mBlockCommentSymbolId{-1} {
    loadParserInfo(parserInfo);
}

void parser::Tokenizer::loadSourceCode(const std::string& sourceCode) {
    // Replace internal source code string with new source code
    mSourceCode = sourceCode + " ";
    // Reset current index
    mSourceCodeIndex = 0;
}

parser::Token parser::Tokenizer::next() {
    // Skip empty space
    skipEmptySpace();

    // Do an end of file check
    if (mSourceCode[mSourceCodeIndex] == 0) {
        return {gcEofSymbolId, nullptr};
    }

    // Remember start index for error message purpose
    auto startIndex = mSourceCodeIndex;

    // Keep track of which symbols are still a possible match
    std::vector<bool> matchable(mSymbols.size());
    for (int i = 0; i < matchable.size(); i++) {
        matchable[i] = mSymbols[i].mcTerminal;
    }
    // Remove special case of EOF symbol
    matchable[gcEofSymbolId] = false;

    // Simple optimization to skip partial matching when only a single symbol is contending
    bool singleMatchLeft = false;
    int matches = 0;
    int latestMatchedSymbolId = -1;

    std::string tokenString;
    char lookahead = mSourceCode[mSourceCodeIndex++];
    while (mSourceCode[mSourceCodeIndex] != 0) {
        tokenString += lookahead;
        lookahead = mSourceCode[mSourceCodeIndex];

        // Count number of partial matches
        if (!singleMatchLeft) {
            matches = 0;
            latestMatchedSymbolId = -1;
            for (int symbolId = 1; symbolId < mSymbols.size(); symbolId++) {
                auto& symbol = mSymbols[symbolId];
                if (matchable[symbolId]) {
                    matchable[symbolId] = std::regex_match(tokenString + lookahead, symbol.mcRegexPartial);

                    if (matchable[symbolId]) {
                        matches++;
                        latestMatchedSymbolId = symbolId;
                    }
                }
            }
        }

        // When only a single partial match is left, check to see if it also matches completely
        if (matches == 1) {
            ASSERT(latestMatchedSymbolId > -1);
            singleMatchLeft = true;

            if (std::regex_match(tokenString + lookahead, mSymbols[latestMatchedSymbolId].mcRegexComplete)) {
                void* data = nullptr;
                switch (mSymbols[latestMatchedSymbolId].mcType) {
                    case STRING:
                        data = static_cast<void*>(stringToStringAllocation(tokenString));
                        break;
                    case CHAR:
                        data = reinterpret_cast<void*>(stringToChar(tokenString));
                        break;
                    case INT:
                        data = reinterpret_cast<void*>(stringToInt(tokenString));
                        break;
                    case NONE:
                        break;
                };

                if (latestMatchedSymbolId == mLineCommentSymbolId ||
                    latestMatchedSymbolId == mBlockCommentSymbolId) {
                    return next();
                }

                // Complete and only match found! Return corresponding token.
                return {latestMatchedSymbolId, data};
            }
        }

        mSourceCodeIndex++;
    }

    if (!tokenString.empty()) {
        LOG_ERR() << "Token was unable to be parsed: " << LOG_NL
                  << "Source code index: " << startIndex << LOG_NL
                  << "Unparsed text: " << LOG_NL
                  << tokenString << LOG_END;
        ASSERT(false); // TODO: Better error handling?
    }

    if (mSourceCode[mSourceCodeIndex] == 0) {
        return {gcEofSymbolId, nullptr};
    } else {
        ASSERT_MSG(false, "This code path should not be reachable.");
        return {gcEofSymbolId, nullptr};
    }
}

void parser::Tokenizer::loadParserInfo(const std::string& info) {
    // First add end-of-file (eof) symbol to the list of symbols
    static_cast<void>(mSymbols.emplace_back(gcEofSymbolId, true));
    DEBUG_CODE(mSymbolIdToNameMap[gcEofSymbolId] = "EOF";)
    // Add empty word symbol to the list of symbols
    static_cast<void>(mSymbols.emplace_back(gcEmptyWordSymbolId, true));
    DEBUG_CODE(mSymbolIdToNameMap[gcEmptyWordSymbolId] = "EMPTY_WORD";)


    // Go through parser info line by line
    std::istringstream infoStream(info);
    std::string line;
    while (std::getline(infoStream, line)) {
        readParserInfoLine(line);
    }

    ASSERT(mLineCommentSymbolId > -1);
    ASSERT(mBlockCommentSymbolId > -1);

    // Add starting rule as last rule in mRules, create its category symbol
    auto& insertedSymbol = mSymbols.emplace_back(mSymbols.size());
    DEBUG_CODE(mSymbolIdToNameMap[mSymbols.size() - 1] = "START";)
    auto& insertedRule = mRules.emplace_back(mRules.size(), &insertedSymbol, -1, std::initializer_list<const Symbol*>{mRules[0].mcCat, &mSymbols[gcEofSymbolId]}, std::initializer_list<bool>{false, false}); // TODO Check correct bools
    static_cast<void>(mRulesByCategory[&insertedSymbol].push_back(insertedRule.mcId));
}

void parser::Tokenizer::readParserInfoLine(const std::string& line) {
    std::istringstream lineStream(line);

    std::string word;
    lineStream >> word;
    if (word == gcParserInfoTerminalLineIdentifier) {
        loadParserInfoTerminalInfo(lineStream);
        return;
    } else if (word == gcParserInfoNonTerminalLineIdentifier) {
        loadParserInfoNonTerminalInfo(lineStream);
        return;
    } else if (word == gcParserInfoRuleLineIdentifier) {
        loadParserInfoRuleInfo(lineStream);
        return;
    } else if (word == gcParserInfoEmptyWordIdentifier) {
        loadParserInfoEmptyWordInfo(lineStream);
        return;
    } else {
        LOG_WRN() << "Unidentifiable lines in parser info (will be skipped)." << LOG_END;
    }
}

void parser::Tokenizer::loadParserInfoTerminalInfo(std::istringstream& lineStream) {
    std::string key;
    std::string regexComplete;
    std::string regexPartial;
    std::string typeString;
    if (!(lineStream >> key >> regexComplete >> regexPartial >> typeString)) {
        ASSERT_MSG(false, "Unable to read terminal info from parser info."); // TODO: Better error handling?
    }

    if (mSymbolNameToIdMap.count(key) == 0) {
        mSymbolNameToIdMap[key] = static_cast<int>(mSymbols.size());
        DEBUG_CODE(mSymbolIdToNameMap[static_cast<int>(mSymbols.size())] = key;)
    } else {
        ASSERT_MSG(false, "Duplicate symbol keys in parser info."); // TODO: Better error handling?
    }

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    // Check for regex duplicates
    auto insertedComplete = mSymbolRegexStrings.insert(regexComplete);
    ASSERT_MSG(insertedComplete.second, "Duplicate complete regex for terminal in parser info.");
    auto insertedPartial = mSymbolRegexStrings.insert(regexPartial);
    ASSERT_MSG(insertedComplete.second, "Duplicate partial regex for terminal in parser info.");
#endif

    SymbolType type;
    if (typeString == gcParserInfoTerminalTypeString) {
        type = SymbolType::STRING;
    } else if (typeString == gcParserInfoTerminalTypeChar) {
        type = SymbolType::CHAR;
    } else if (typeString == gcParserInfoTerminalTypeInt) {
        type = SymbolType::INT;
    } else if (typeString == gcParserInfoTerminalTypeVoid) {
        type = SymbolType::NONE;
    } else {
        LOG_ERR() << "Can not identify terminal type \"" << typeString << "\" from parser info for key \"" << key << "\"." << LOG_END;
        ASSERT(false); // TODO: Better error handling?
    }

    if (key == gcParserInfoLineCommentIdentifier) {
        mLineCommentSymbolId = static_cast<int>(mSymbols.size());
    } else if (key == gcParserInfoBlockCommentIdentifier) {
        mBlockCommentSymbolId = static_cast<int>(mSymbols.size());
    }

    static_cast<void>(mSymbols.emplace_back(mSymbols.size(), type, regexComplete, regexPartial));
}

void parser::Tokenizer::loadParserInfoNonTerminalInfo(std::istringstream& lineStream) {
    std::string key;
    if (!(lineStream >> key)) {
        ASSERT_MSG(false, "Unable to read non-terminal info from parser info."); // TODO: Better error handling?
    }

    if (mSymbolNameToIdMap.count(key) == 0) {
        mSymbolNameToIdMap[key] = static_cast<int>(mSymbols.size());
        DEBUG_CODE(mSymbolIdToNameMap[static_cast<int>(mSymbols.size())] = key;)
    } else {
        ASSERT_MSG(false, "Duplicate symbol keys in parser info."); // TODO: Better error handling?
    }

    static_cast<void>(mSymbols.emplace_back(mSymbols.size()));
}

void parser::Tokenizer::loadParserInfoRuleInfo(std::istringstream& lineStream) {
    // Find pointer to category symbol
    std::string categorySymbolKey;
    lineStream >> categorySymbolKey;

    int categorySymbolId = -1;
    if (mSymbolNameToIdMap.count(categorySymbolKey) == 1) {
        categorySymbolId = mSymbolNameToIdMap[categorySymbolKey];
    } else {
        ASSERT_MSG(false, "Symbol used as rule category in parser info was not declared before rule was declared."); // TODO: Better error handling?
    }

    ASSERT(categorySymbolId > -1);
    auto categorySymbolPointer = &mSymbols[categorySymbolId];

    // Find pointers to production symbols
    std::vector<const Symbol*> productionSymbolsPointers;
    std::string productionSymbolKey;
    for (lineStream >> productionSymbolKey; productionSymbolKey != gcParserInfoRuleLineProductionEndIdentifier; lineStream >> productionSymbolKey) {
        if (mSymbolNameToIdMap.count(productionSymbolKey) == 1) {
            auto productionSymbolId = mSymbolNameToIdMap[productionSymbolKey];
            productionSymbolsPointers.push_back(&mSymbols[productionSymbolId]);
        } else {
            ASSERT_MSG(false, "Symbol used as rule product in parser info was not declared before rule was declared."); // TODO: Better error handling?
        }
    }

    // Find if production symbols contain data
    std::vector<bool> productionSymbolsDataFlags;
    std::string productionSymbolDataFlag;
    for (lineStream >> productionSymbolDataFlag; productionSymbolDataFlag != gcParserInfoRuleLineProductionEndIdentifier; lineStream >> productionSymbolDataFlag) {
        if (productionSymbolDataFlag == "void") {
            productionSymbolsDataFlags.push_back(false);
        } else {
            productionSymbolsDataFlags.push_back(true);
        }
    }
    ASSERT_MSG(productionSymbolsDataFlags.size() == productionSymbolsPointers.size(), "Parser info did not supply correct number of data flags for rule.");

    std::string vtableIdString;
    if (!(lineStream >> vtableIdString)) {
        ASSERT_MSG(false, "Can not find rule vtable id in parser info."); // TODO: Better error handling?
    }

    auto& inserted = mRules.emplace_back(mRules.size(), categorySymbolPointer, stringToInt(vtableIdString), productionSymbolsPointers, productionSymbolsDataFlags);
    static_cast<void>(mRulesByCategory[categorySymbolPointer].push_back(inserted.mcId));
}

void parser::Tokenizer::loadParserInfoEmptyWordInfo(std::istringstream& lineStream) {
    std::string key;
    if (!(lineStream >> key)) {
        ASSERT_MSG(false, "Unable to read empty word info from parser info."); // TODO: Better error handling?
    }

    if (mSymbolNameToIdMap.count(key) == 0) {
        mSymbolNameToIdMap[key] = gcEmptyWordSymbolId;
    } else {
        ASSERT_MSG(false, "Duplicate symbol keys in parser info."); // TODO: Better error handling?
    }
}

void parser::Tokenizer::skipEmptySpace() {
    while (isEmptySpace(mSourceCode[mSourceCodeIndex])) {
        mSourceCodeIndex++;
    }
}

bool parser::Tokenizer::isEmptySpace(char c) {
    return c == ' '    ||
           c == '\t'   ||
           c == '\n'   ||
           c == '\r';
}

int parser::Tokenizer::stringToInt(std::string &str) {
    int parsed;
    char* start = &str[0];
    char* end = &str[str.size()];
    auto result = std::from_chars(start, end, parsed);
    ASSERT(!static_cast<bool>(result.ec) && result.ptr == end); // TODO: Better error handling?
    return parsed;
}

char parser::Tokenizer::stringToChar(std::string& str) {
    if (str.size() == 1) {
        return str[0];
    } else if (str.size() == 3) {
        ASSERT(str[0] == '\'' && str[2] == '\'');
        return str[1];
    } else if (str.size() == 4) {
        ASSERT(str[0] == '\'' && str[1] == '\\' && str[3] == '\'');
        ASSERT(str[2] == '\'' || str[2] == '\"' || str[2] == '\\'); // TODO: Make more official
        return str[2];
    } else {
        LOG_ERR() << "\"" << str << "\" is not parseable to a char." << LOG_END;
        ASSERT(false); // TODO: Better error handling?
        return 0;
    }
}

char* parser::Tokenizer::stringToStringAllocation(std::string& str) {
   if (str[0] == '\"') {
       ASSERT(str[str.size() - 1] == '\"');
       int numCharacters = str.size() - 2;
       auto* data = new char[numCharacters + 1]; // Remove quotation marks and add \0 character
       for (int i = 0; i < numCharacters; i++) {
           data[i] = str[i + 1];
       }
       data[numCharacters] = 0;
       return data;
   } else {
       auto* data = new char[str.size() + 1]; // Add \0 character
       for (int i = 0; i < str.size(); i++) {
           data[i] = str[i];
       }
       data[str.size()] = 0;
       return data;
   }
}
