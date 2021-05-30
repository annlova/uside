//
// Created by Anton on 2020-07-18.
//

#include "grammar.h"

template<class Return, class Argument>
Return absyn::bnf::GrammarListDef<Return, Argument>::accept(absyn::bnf::GrammarVisitor* v, Argument arg) {
    return v->visit(this, arg);
}