//
// Created by Anton on 2021-05-26.
//

#ifndef USIDE_SRC_PARSER_H_TOKEN_H
#define USIDE_SRC_PARSER_H_TOKEN_H

#include "symbol.h"

namespace parser {
    // Forward declare Symbol
    struct Symbol;

    struct Token {
        const int mcId;
        const void* const mcData;

        Token(int id, void* data) : mcId(id), mcData{data} {}

        bool operator==(const Symbol& other) const;
        bool operator!=(const Symbol& other) const;
    };
}
#endif //USIDE_SRC_PARSER_H_TOKEN_H
