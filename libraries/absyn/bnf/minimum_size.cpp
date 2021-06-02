//
// Created by Anton on 2020-07-18.
//

#include "minimum_size.h"

void absyn::bnf::MinimumSizeEpsilon::accept(MinimumSizeVisitor& v) const {
    v.visit(*this);
}

void absyn::bnf::MinimumSizeNonempty::accept(MinimumSizeVisitor& v) const {
    v.visit(*this);
}
