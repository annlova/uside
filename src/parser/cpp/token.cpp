//
// Created by Anton on 2021-05-26.
//

#include "../h/token.h"

bool parser::Token::operator==(const parser::Symbol& other) const {
    return mcId == other.mcId;
}

bool parser::Token::operator!=(const parser::Symbol& other) const {
    return mcId != other.mcId;
}
