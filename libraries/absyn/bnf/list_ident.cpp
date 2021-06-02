//
// Created by Anton on 2020-07-18.
//

#include "list_ident.h"

void absyn::bnf::ListIdentIdent::accept(ListIdentVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListIdentIdentList::accept(ListIdentVisitor& v) const {
    v.visit(*this);
}
