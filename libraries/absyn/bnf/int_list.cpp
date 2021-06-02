//
// Created by Anton on 2020-07-18.
//

#include "int_list.h"

void absyn::bnf::IntListListInteger::accept(IntListVisitor& v) const {
    v.visit(*this);
}
