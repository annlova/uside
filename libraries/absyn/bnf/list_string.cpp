//
// Created by Anton on 2020-07-18.
//

#include "list_string.h"

void absyn::bnf::ListStringList::accept(ListStringVisitor* v) {
    v->visit(this);
}

void absyn::bnf::ListStringString::accept(ListStringVisitor* v) {
    v->visit(this);
}
