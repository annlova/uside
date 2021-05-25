//
// Created by Anton on 2021-05-24.
//

#include "../h/token.h"

#include <assertion/include/assertion_include.h>

bool parser::Token::operator==(const Token& other) const {
    bool equal = mcId == other.mcId;
    ASSERT(!equal || equal && mcTerminal == other.mcTerminal);
    return equal;
}


bool parser::Token::operator!=(const parser::Token& other) const {
    bool unequal = mcId != other.mcId;
    ASSERT(unequal || !unequal && mcTerminal == other.mcTerminal);
    return unequal;
}