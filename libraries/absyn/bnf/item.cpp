//
// Created by Anton on 2020-07-18.
//

#include "item.h"

void absyn::bnf::ItemCat::accept(ItemVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ItemString::accept(ItemVisitor& v) const {
    v.visit(*this);
}
