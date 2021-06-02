//
// Created by Anton on 2020-07-18.
//

#include "list_integer.h"

void absyn::bnf::ListIntegerInteger::accept(ListIntegerVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListIntegerIntegerList::accept(ListIntegerVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListIntegerEmpty::accept(ListIntegerVisitor& v) const {
    v.visit(*this);
}
