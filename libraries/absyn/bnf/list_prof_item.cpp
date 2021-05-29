//
// Created by Anton on 2020-07-18.
//

#include "list_prof_item.h"

void absyn::bnf::ListProfItemProfItem::accept(ListProfItemVisitor* v) {
    v->visit(this);
}

void absyn::bnf::ListProfItemList::accept(ListProfItemVisitor* v) {
    v->visit(this);
}
