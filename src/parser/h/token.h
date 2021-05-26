//
// Created by Anton on 2021-05-26.
//

#ifndef USIDE_SRC_PARSER_H_TOKEN_H
#define USIDE_SRC_PARSER_H_TOKEN_H

#include "symbol.h"

namespace parser {
    struct Token {
        int mId;
        const void* mData;

        Token(int id, void* data) : mId(id), mData{data} {}

        bool operator==(const Symbol& other) const;
        bool operator!=(const Symbol& other) const;
    };
}
#endif //USIDE_SRC_PARSER_H_TOKEN_H
