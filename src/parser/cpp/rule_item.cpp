//
// Created by Anton on 2021-05-24.
//

#include "../h/rule_item.h"

#include <iostream>

#include <assertion/include/assertion_include.h>

parser::RuleItem::RuleItem(const std::vector<Rule>& rules, const int ruleId, const int index, const parser::Token* lookahead)
        : mcRule(&rules[ruleId]), mcIndex(index), mLookahead(lookahead), mActionAccept(false), mActionReduce(false) {

    // Check if this rule item will incur an accept action
    if (index < mcRule->mcPrd.size() &&
        mcRule->mcPrd[index]->mcId == gcEofTokenId) {
        mActionAccept = true;
    }

    // Check if this rule item will incur a reduce action
    // TODO: possible improvement, make rules list indexed for faster lookup
    for (int i = 0; i < rules.size(); i++) {
        if(rules[i].isReductionOf(mcRule, index)) {
            ASSERT_MSG(!mActionReduce, "Error! Item can be reduced to multiple rules!");
            mActionReduce = true;
            mActionReduceRuleId = i;
        }
    }
}