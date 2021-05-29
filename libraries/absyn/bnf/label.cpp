//
// Created by Anton on 2020-07-18.
//

#include "label.h"

void absyn::bnf::LabelDoubleLabelIdListProfItem::accept(LabelVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelLabelIdListProfItem::accept(LabelVisitor* v) {
    v->visit(this);
}

void absyn::bnf::LabelLabelId::accept(LabelVisitor* v) {
    v->visit(this);
}
