//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_RULE_H
#define USIDE_SRC_PARSER_H_RULE_H

#include <vector>

#include "token.h"

namespace parser {
        struct Rule {
            const int mcId;
            const Token* const mcCat;
            const std::vector<Token*> mcPrd;

            Rule(const int id, const Token* const cat, const std::vector<Token*> prd) : mcId(id), mcCat(cat), mcPrd(std::move(prd)) {}

            bool isReductionOf(const Rule* const rule, int index) const;
        };
}

#endif //USIDE_SRC_PARSER_H_RULE_H
