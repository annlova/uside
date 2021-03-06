//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_SYMBOL_H
#define USIDE_SRC_PARSER_H_SYMBOL_H

#include <cstddef>
#include <memory>
#include <string>
#include <regex>

//#include "token.h"

namespace parser {
    enum SymbolType {
        STRING,
        CHAR,
        INT,
        NONE
    };

    struct Symbol {
        const int mcId;
        const SymbolType mcType;
        const bool mcTerminal;
        const std::regex mcRegexComplete;
        const std::regex mcRegexPartial;

        Symbol(int id, bool terminal = false) : mcId(id), mcTerminal(terminal), mcType(SymbolType::NONE), mcRegexComplete(), mcRegexPartial(){}
        Symbol(int id, SymbolType type, std::string& regexComplete, std::string& regexPartial) : mcId(id), mcTerminal(true), mcType(type),
                                                                                mcRegexComplete(regexComplete, std::regex_constants::optimize | std::regex_constants::ECMAScript),
                                                                                mcRegexPartial(regexPartial, std::regex_constants::optimize | std::regex_constants::ECMAScript) {}

//            bool operator==(const Token& other) const;
//            bool operator!=(const Token& other) const;
    };

    struct SymbolHasher {
        std::size_t operator()(const Symbol& symbol) const {
            return std::hash<int>()(symbol.mcId);
        }
    };
}

#endif //USIDE_SRC_PARSER_H_SYMBOL_H
