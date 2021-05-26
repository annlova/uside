//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_RULE_ITEM_H
#define USIDE_SRC_PARSER_H_RULE_ITEM_H

#include "rule.h"
#include "symbol.h"

namespace parser {
        struct RuleItem {
            const Rule* const mcRule;
            const int mcIndex;
            const Symbol* const mcLookahead;

            bool mActionAccept;
            bool mActionReduce;
            int mActionReduceRuleId;

            RuleItem(const std::vector<Rule>& rules, const int ruleId, const int index, const Symbol* lookahead);

            bool operator==(const RuleItem& other) const {
                return mcRule == other.mcRule && mcIndex == other.mcIndex && mcLookahead == other.mcLookahead;
            }
        };

        struct RuleItemHasher {
            std::size_t operator()(const RuleItem& i) const {
                SymbolHasher symbolHasher;
                return 51 + 51 * std::hash<int>()(i.mcIndex) + 13 * symbolHasher(*i.mcLookahead) + std::hash<const Rule*>()(i.mcRule);
            }
        };
}

#endif //USIDE_SRC_PARSER_H_RULE_ITEM_H
