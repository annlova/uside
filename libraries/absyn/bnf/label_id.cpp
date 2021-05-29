//
// Created by Anton on 2020-07-18.
//

#include "label_id.h"

void absyn::bnf::LabelIdBracketsColonSquare::accept(LabelIdVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelIdIdent::accept(LabelIdVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelIdBracketsColon::accept(LabelIdVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelIdSquareBrackets::accept(LabelIdVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelIdUnderscore::accept(LabelIdVisitor* v) {
    v->visit(this);
}
