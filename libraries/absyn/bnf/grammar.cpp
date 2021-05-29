//
// Created by Anton on 2020-07-18.
//

#include "grammar.h"

void absyn::bnf::GrammarListDef::accept(GrammarVisitor* v) {
    v->visit(this);
}
