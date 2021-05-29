//
// Created by Anton on 2020-07-18.
//

#include "list_def.h"

void absyn::bnf::ListDefEpsilon::accept(ListDefVisitor* v) {
    v->visit(this);
}

void absyn::bnf::ListDefList::accept(ListDefVisitor* v) {
    v->visit(this);
}
