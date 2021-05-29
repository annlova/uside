//
// Created by Anton on 2021-05-24.
//

#include "../h/rule_item.h"

#include <configs/parser_config.h>
#include <assertion/include/assertion_include.h>
#include <globals/debug_code_maco.h>

parser::RuleItem::RuleItem(const std::vector<Rule>& rules, const int ruleId, const int index, const parser::Symbol* lookahead)
        : mcRule(&rules[ruleId]), mcIndex(index), mcLookahead(lookahead), mActionAccept(false), mActionReduce(false) {

    // Check if this rule item will incur an accept action
    if (index < mcRule->mcPrd.size() &&
        mcRule->mcPrd[index]->mcId == gcEofSymbolId) {
        mActionAccept = true;
    }

//    // Check if this rule item will incur a reduce action
//    // TODO: possible improvement, make rules list indexed for faster lookup
////    DEBUG_CODE(std::vector<int> reducable;)
//    for (int i = 0; i < rules.size(); i++) {
//        if(rules[i].isReductionOf(mcRule, index)) {
////            ASSERT_MSG(!mActionReduce, "Error! Item can be reduced to multiple rules!"); TODO: Check if correct
//            mActionReduce = true;
//            mActionReduceRuleId = i; // TODO FIX!!!
////            DEBUG_CODE(reducable.push_back(i);)
//        }
//    }

    if (index == mcRule->mcPrd.size() || index == mcRule->mcPrd.size() - 1 && mcRule->mcPrd[index]->mcId == gcEmptyWordSymbolId) {
        mActionReduce = true;
        mActionReduceRuleId = mcRule->mcId;
    }
}