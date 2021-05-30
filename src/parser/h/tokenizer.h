//
// Created by Anton on 2021-05-26.
//

#ifndef USIDE_SRC_PARSER_H_TOKENIZER_H
#define USIDE_SRC_PARSER_H_TOKENIZER_H

#include <vector>
#include <unordered_map>
#include <string>
#include <istream>

#include <globals/debug_code_maco.h>

#include "rule.h"
#include "symbol.h"
#include "token.h"

#if USIDE_WITH_FEATURE_DEBUG_CODE()
// Used to check for regex duplicates, without only the key is checked
#include <unordered_set>
#endif

namespace parser {

    class Tokenizer {
    public:
        Tokenizer(const std::string& parserInfo);

    public:
        void loadSourceCode(const std::string& sourceCode);
        Token next();

    private:
        void loadParserInfo(const std::string& info);
        void readParserInfoLine(const std::string& line);
        void loadParserInfoTerminalInfo(std::istringstream& lineStream);
        void loadParserInfoNonTerminalInfo(std::istringstream& lineStream);
        void loadParserInfoRuleInfo(std::istringstream& lineStream);
        void loadParserInfoEmptyWordInfo(std::istringstream& lineStream);

    private:
        void skipEmptySpace();
        static bool isEmptySpace(char c);
        static int stringToInt(std::string& str);
        static char stringToChar(std::string& str);
        static char* stringToStringAllocation(std::string& str);

    public:
        const std::vector<Rule>& getRules() const { return mRules; }
        const std::unordered_map<const Symbol*, std::vector<int>>& getRulesByCategory() const { return mRulesByCategory; }
        const std::vector<Symbol>& getSymbols() const { return mSymbols; }
        DEBUG_CODE(const std::unordered_map<int COMMA std::string>& getSymbolIdToNameMap() const { return mSymbolIdToNameMap; })

    private:
        /// Contains the rules of the grammar from the supplied parserInfo.
        std::vector<Rule> mRules;
        /// Contains the rules sorted by category.
        std::unordered_map<const Symbol*, std::vector<int>> mRulesByCategory;

        /// Contains the symbols of the grammar from the supplied parserInfo.
        std::vector<Symbol> mSymbols;
        /// Contains ids (index to mSymbols) of symbols sorted by symbol key string in parserInfo.
        std::unordered_map<std::string, int> mSymbolNameToIdMap;

        // Used to check for regex duplicates, without only the key is checked
        DEBUG_CODE(std::unordered_set<std::string> mSymbolRegexStrings;)
        // Used to print token keys in plain text for debugging
        DEBUG_CODE(std::unordered_map<int COMMA std::string> mSymbolIdToNameMap;)

        std::string mSourceCode;
        int mSourceCodeIndex;

        int mLineCommentSymbolId;
        int mBlockCommentSymbolId;
    };
}
#endif //USIDE_SRC_PARSER_H_TOKENIZER_H
