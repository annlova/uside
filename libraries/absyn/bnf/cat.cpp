//
// Created by Anton on 2021-05-28.
//

#include "cat.h"

void absyn::bnf::CatIdent::accept(CatVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::CatSquare::accept(CatVisitor& v) const {
    v.visit(*this);
}
