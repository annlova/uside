//
// Created by Anton on 2021-05-26.
//

#include "../h/tokenizer.h"

#include <regex>
#include <charconv>

#include <configs/parser_config.h>
#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>

parser::Tokenizer::Tokenizer(const std::string& parserInfo) : mRules(), mRulesByCategory(), mSymbols(), mSymbolNameToIdMap() DEBUG_CODE(COMMA mSymbolRegexStrings() COMMA mSymbolIdToNameMap()), mSourceCode(), mSourceCodeIndex{0} {
    loadParserInfo(parserInfo);
}

void parser::Tokenizer::loadSourceCode(const std::string& sourceCode) {
    // Replace internal source code string with new source code
    mSourceCode = sourceCode + " ";
    // Reset current index
    mSourceCodeIndex = 0;
}

parser::Token parser::Tokenizer::next() {
    auto startIndex = mSourceCodeIndex;

    // Keep track of which symbols are still a possible match
    std::vector<bool> matchable(mSymbols.size());
    for (int i = 0; i < matchable.size(); i++) {
        matchable[i] = mSymbols[i].mcTerminal;
    }

    // Simple optimization to skip partial matching when only a single symbol is contending
    bool singleMatchLeft = false;
    int matches = 0;
    int latestMatchedSymbolId = -1;

    std::string tokenString;
    while (mSourceCode[mSourceCodeIndex] != 0) {
        char nextCharacter = mSourceCode[mSourceCodeIndex];
        // Skip empty space
        if (tokenString.empty()     && (
            nextCharacter == ' '    ||
            nextCharacter == '\t'   ||
            nextCharacter == '\n'   ||
            nextCharacter == '\r'
            )) {
            mSourceCodeIndex++;
            continue;
        }

        tokenString += nextCharacter;

        // Count number of partial matches
        if (!singleMatchLeft) {
            matches = 0;
            latestMatchedSymbolId = -1;
            for (int symbolId = 1; symbolId < mSymbols.size(); symbolId++) {
                auto& symbol = mSymbols[symbolId];
                if (matchable[symbolId]) {
                    matchable[symbolId] = std::regex_match(tokenString, symbol.mcRegexPartial);

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

            if (std::regex_match(tokenString, mSymbols[latestMatchedSymbolId].mcRegexComplete)) {
                void* data = nullptr;
                switch (mSymbols[latestMatchedSymbolId].mcType) {
                    case STRING:
                        data = new char[tokenString.size() + 1];
                        for (int i = 0; i < tokenString.size() + 1; i++) {
                            static_cast<char*>(data)[i] = tokenString[i];
                        }
                        break;
                    case CHAR:
                        ASSERT(tokenString.size() == 1);
                        data = reinterpret_cast<void*>(tokenString[0]);
                        break;
                    case INT:
                        data = reinterpret_cast<void*>(stringToInt(tokenString));
                        break;
                    case NONE:
                        break;
                };
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
    static_cast<void>(mSymbols.emplace_back(gcEofSymbolId));

    // Go through parser info line by line
    std::istringstream infoStream(info);
    std::string line;
    while (std::getline(infoStream, line)) {
        readParserInfoLine(line);
    }
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
    std::vector<Symbol*> productionSymbolsPointers;
    std::string productionSymbolKey;
    for (lineStream >> productionSymbolKey; productionSymbolKey != gcParserInfoRuleLineProductionEndIdentifier; lineStream >> productionSymbolKey) {
        if (mSymbolNameToIdMap.count(productionSymbolKey) == 1) {
            auto productionSymbolId = mSymbolNameToIdMap[productionSymbolKey];
            productionSymbolsPointers.push_back(&mSymbols[productionSymbolId]);
        } else {
            ASSERT_MSG(false, "Symbol used as rule product in parser info was not declared before rule was declared."); // TODO: Better error handling?
        }
    }

    static_cast<void>(mRules.emplace_back(mRules.size(), categorySymbolPointer, productionSymbolsPointers));
    static_cast<void>(mRulesByCategory[categorySymbolPointer].push_back(static_cast<int>(mRules.size())));
}

int parser::Tokenizer::stringToInt(std::string &str) {
    int parsed;
    char* start = &str[0];
    char* end = &str[str.size()];
    auto result = std::from_chars(start, end, parsed);
    ASSERT(static_cast<bool>(result.ec) && result.ptr == end); // TODO: Better error handling?
    return parsed;
}
