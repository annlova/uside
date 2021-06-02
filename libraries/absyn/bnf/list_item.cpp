//
// Created by Anton on 2020-07-18.
//

#include "list_item.h"

void absyn::bnf::ListItemItemList::accept(ListItemVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::ListItemEpsilon::accept(ListItemVisitor& v) const {
    v.visit(*this);
}
