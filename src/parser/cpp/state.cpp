//
// Created by Anton on 2021-05-24.
//

#include "../h/state.h"

#include <configs/parser_config.h>
#include <logs/include/log_include.h>
#include <assertion/h/assertion_macro.h>

std::size_t parser::StateHasher::operator()(const parser::State& state) const {
    std::size_t sum = 0;
    RuleItemHasher hasher;
    for (auto e: state.mItems) {
        sum += hasher(e);
    }
    return std::hash<std::size_t>()(sum);
}

bool parser::State::operator==(const parser::State& other) const {
    return mItems == other.mItems;
}

void parser::State::closure(const std::vector<Rule>& rules, const std::unordered_map<const Symbol*, std::vector<int>>& rulesByCategory) {
    bool itemsAdded = false;

    for (auto& item: mItems) {
        if (item.mcIndex < item.mcRule->mcPrd.size() &&
            !item.mcRule->mcPrd[item.mcIndex]->mcTerminal) {
            // Next symbol exists and is non-terminal - add new items to the new state for each rule the non-terminal is the category for
            std::vector<const Symbol*> lookaheads;
            if (item.mcIndex + 1 == item.mcRule->mcPrd.size()) {
                lookaheads.push_back(item.mcLookahead);
            } else {
                auto lookahead = item.mcRule->mcPrd[item.mcIndex + 1];
                if (lookahead->mcTerminal) {
                    lookaheads.push_back(lookahead);
                } else {
                    std::vector<int> search;
                    std::unordered_set<int> searchSet;
                    for (auto e: rulesByCategory.at(lookahead)) {
                        search.push_back(e);
                        searchSet.insert(e);
                    }
                    for (int i = 0; i < search.size(); i++) {
                        auto* symbol = rules[i].mcPrd[0];
                        if (symbol->mcTerminal) {
                            lookaheads.push_back(symbol);
                        } else {
                            for (auto e: rulesByCategory.at(symbol)) {
                                auto inserted = searchSet.insert(e);
                                if (inserted.second) {
                                    search.push_back(e);
                                }
                            }
                        }
                    }
                }
            }

            auto categoryRules = rulesByCategory.at(item.mcRule->mcPrd[item.mcIndex]);
            for (auto ruleIndex: categoryRules) {
                for (auto lookahead: lookaheads) {
                    auto inserted = mItems.emplace(rules, ruleIndex, 0, lookahead);
                    if (inserted.second) {
                        // New rule item added - keep track
                        itemsAdded = true;
                        // TODO: Fix inefficiency
                    }
                }
            }
        }
    }

    if (itemsAdded) {
        closure(rules, rulesByCategory);
    }
}

void parser::State::findNextStates(std::vector<const State*>& table,
                                   const std::vector<Rule>& rules,
                                   const std::unordered_map<const Symbol*, std::vector<int>>& rulesByCategory,
                                   std::unordered_set<State, StateHasher>& states) const {
    // Sort the states existing rules by category. Each category will create a new state.
    std::unordered_map<const Symbol*, std::vector<RuleItem>> itemsByCategory;
    for (auto& item: mItems) {
        auto rule = item.mcRule;
        auto index = item.mcIndex;
        auto symbol = rule->mcPrd[index];
        auto lookahead = item.mcLookahead;

        if (index < rule->mcPrd.size() &&
            symbol->mcId != gcEofSymbolId) {
            static_cast<void>(itemsByCategory[symbol].emplace_back(rules, rule->mcId, index + 1, lookahead));
        }
    }

    // Go through each rule category and construct a new state
    for (auto& categoryItems: itemsByCategory) {
        int stateId = static_cast<int> (table.size());
        State newState(stateId, static_cast<int>(mActionTableRow.size()));

        bool accept = false;
        bool reduce = false;
        std::vector<int> reduceRules(mActionTableRow.size(), -1);
        for (auto& item : categoryItems.second) {
            auto inserted = newState.mItems.insert(item);
            if (inserted.second) {
                if (item.mActionAccept) {
                    accept = true;
                }

                if (item.mActionReduce) {
                    reduce = true;
                    reduceRules[item.mcLookahead->mcId] = item.mActionReduceRuleId;
                }
            } else {
                LOG_WRN() << "Attempted duplicate insertion of rule item in new state." << LOG_END;
            }
        }

        newState.closure(rules, rulesByCategory);

        auto inserted = states.insert(std::move(newState));

        auto& sym = categoryItems.first;
        if (sym->mcTerminal) {
            mActionTableRow[sym->mcId] = {Action::SHIFT, inserted.first->mcId};
        } else {
            mActionTableRow[sym->mcId] = {Action::GOTO, inserted.first->mcId};
        }

        if (inserted.second) {
            table.push_back(&(*inserted.first));

            const auto* actionTableState = table[table.size() - 1];
            for (auto& e: actionTableState->mActionTableRow) {
                e = {Action::NA, -1};
            }

            if (reduce) {
                auto& row = actionTableState->mActionTableRow;
                for (int i = 0; i < row.size(); i++) {
                    if (row[i].mAction != Action::GOTO && reduceRules[i] > -1) {
                        row[i].mAction = Action::REDUCE;
                        row[i].mActionPointer = reduceRules[i];
                    }
                }
            }

            if (accept) {
                actionTableState->mActionTableRow[gcEofSymbolId] = {Action::ACCEPT, 0}; // EOF column
            }

            inserted.first->findNextStates(table, rules, rulesByCategory, states);
        }
    }
}