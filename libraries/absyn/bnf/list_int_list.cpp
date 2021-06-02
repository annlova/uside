//
// Created by Anton on 2020-07-18.
//

#include "list_int_list.h"

void absyn::bnf::ListIntListIntList::accept(ListIntListVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListIntListEpsilon::accept(ListIntListVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListIntListIntListList::accept(ListIntListVisitor& v) const {
    v.visit(*this);
}
