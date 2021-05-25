//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_RULE_ITEM_H
#define USIDE_SRC_PARSER_H_RULE_ITEM_H

#include "rule.h"
#include "token.h"

namespace parser {
        struct RuleItem {
            const Rule* const mcRule;
            const int mcIndex;
            const Token* mLookahead;

            bool mActionAccept;
            bool mActionReduce;
            int mActionReduceRuleId;

            RuleItem(const std::vector<Rule>& rules, const int ruleId, const int index, const Token* lookahead);

            bool operator==(const RuleItem& other) const {
                return mcRule == other.mcRule && mcIndex == other.mcIndex && mLookahead == other.mLookahead;
            }
        };

        struct RuleItemHasher {
            std::size_t operator()(const RuleItem& i) const {
                TokenHasher tokenHasher;
                return 51 + 51 * std::hash<int>()(i.mcIndex) + 13 * tokenHasher(*i.mLookahead) + std::hash<const Rule*>()(i.mcRule);
            }
        };
}

#endif //USIDE_SRC_PARSER_H_RULE_ITEM_H
