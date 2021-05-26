//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_RULE_H
#define USIDE_SRC_PARSER_H_RULE_H

#include <vector>

#include "symbol.h"

namespace parser {
        struct Rule {
            const int mcId;
            const Symbol* const mcCat;
            const std::vector<Symbol*> mcPrd;

            Rule(const int id, const Symbol* const cat, const std::vector<Symbol*> prd) : mcId(id), mcCat(cat), mcPrd(std::move(prd)) {}

            bool isReductionOf(const Rule* const rule, int index) const;
        };
}

#endif //USIDE_SRC_PARSER_H_RULE_H
