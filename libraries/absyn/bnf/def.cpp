//
// Created by Anton on 2020-07-18.
//

#include "def.h"

void absyn::bnf::DefLabel::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefToken::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefBlockComment::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefTerminator::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefLayoutTopLevel::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefLayoutStop::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefPositionToken::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefRules::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefSeparator::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefEntryPoints::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefInternal::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefLineComment::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefLayout::accept(DefVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::DefCoercions::accept(DefVisitor& v) const {
    v.visit(*this);
}


