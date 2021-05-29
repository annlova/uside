//
// Created by Anton on 2020-07-18.
//

#include "rhs.h"

void absyn::bnf::RHSListItem::accept(RHSVisitor* v) {
    v->visit(this);
}
