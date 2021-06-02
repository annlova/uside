//
// Created by Anton on 2020-07-18.
//

#include "prof_item.h"

void absyn::bnf::ProfItemBrackets::accept(ProfItemVisitor& v) const {
    v.visit(*this);
}
