//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_STATE_H
#define USIDE_SRC_PARSER_H_STATE_H

#include <unordered_set>
#include <unordered_map>

#include "rule_item.h"
#include "action_table_element.h"

namespace parser {

    struct State;

    struct StateHasher {
        std::size_t operator()(const State& state) const;
    };

    struct State {
        const int mcId;
        std::unordered_set<RuleItem, RuleItemHasher> mItems;

        mutable std::vector<ActionTableElement> mActionTableRow;

        explicit State(const int id, const int numSymbols) : mcId(id), mItems{}, mActionTableRow(numSymbols) {}

        bool operator==(const State& other) const;

        void closure(const std::vector<Rule>& rules, const std::unordered_map<const Symbol*, std::vector<int>>& rulesByCategory);

        void findNextStates(std::vector<const State*>& table,
                            const std::vector<Rule>& rules,
                            const std::unordered_map<const Symbol*, std::vector<int>>& rulesByCategory,
                            std::unordered_set<State, StateHasher>& states) const;
    };
}

#endif //USIDE_SRC_PARSER_H_STATE_H
