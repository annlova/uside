//
// Created by Anton on 2020-07-18.
//

#include "reg.h"

void absyn::bnf::RegLetter::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegDigit::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegSquareString::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegStar::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegMinus::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegPlus::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegReg::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegQuestion::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegUpper::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegOr::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegChar::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegRealChar::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegCurlyString::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegLower::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegEps::accept(RegVisitor* v) {
    v->visit(this);
}

void absyn::bnf::RegDoubleReg::accept(RegVisitor* v) {
    v->visit(this);
}
