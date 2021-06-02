//
// Created by Anton on 2020-07-18.
//

#include "list_rhs.h"

void absyn::bnf::ListRHSRHS::accept(ListRHSVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListRHSList::accept(ListRHSVisitor& v) const {
    v.visit(*this);
}
