//
// Created by Anton on 2021-05-25.
//

#ifndef USIDE_SRC_PARSER_H_PARSER_H
#define USIDE_SRC_PARSER_H_PARSER_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <configs/parser_config.h>
#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <file/include/file_include.h>

#include "state.h"
#include "rule.h"
#include "rule_item.h"
#include "symbol.h"
#include "tokenizer.h"

namespace parser {
    class Parser {
    public:
        Parser () {
            auto parserInfo = file::FileLoader::readText("res/parser/parser.inf");
            auto sourceCode = file::FileLoader::readText("res/parser/example.bnf");

            Tokenizer tokenizer(parserInfo);
            tokenizer.loadSourceCode(sourceCode);

            auto& idToString = tokenizer.getSymbolIdToNameMap();

            int id = -1;
            while ((id = tokenizer.next().mcId) != gcEofSymbolId) {
                ASSERT(id > -1);
                LOG() << idToString.at(id) << LOG_END;
            }

            LOG() << "End of file reached!" << LOG_END;
        }
//        Parser() {
//            const int numTokens = 6;
//            std::string shaggydog = "";
//            Symbol END(0, shaggydog, shaggydog);
//            Symbol S(4);
//            Symbol C(5);
//            Symbol c(1, shaggydog, shaggydog);
//            Symbol d(2, shaggydog, shaggydog);
//            Symbol SPRIME(3);
//
//            std::vector<Rule> rules;
//            rules.emplace_back(0, &SPRIME, std::initializer_list<Symbol*>{&S, &END});
//            rules.emplace_back(1, &S, std::initializer_list<Symbol*>{&C, &C});
//            rules.emplace_back(2, &C, std::initializer_list<Symbol*>{&c, &C});
//            rules.emplace_back(3, &C, std::initializer_list<Symbol*>{&d});
//
//            std::unordered_map<Symbol*, std::vector<int>> rulesByCategory;
//            rulesByCategory[&SPRIME].push_back(0);
//            rulesByCategory[&S].push_back(1);
//            rulesByCategory[&C].push_back(2);
//            rulesByCategory[&C].push_back(3);
//
//            RuleItem initalStateRuleItem(rules, 0, 0, &END);
//            State initialState(0, numTokens);
//            initialState.mItems.insert(initalStateRuleItem);
//            for(auto& e: initialState.mActionTableRow) {
//                e.mAction = Action::NA;
//                e.mActionPointer = -1;
//            }
//
//            initialState.closure(rules, rulesByCategory);
//
//            std::unordered_set<State, StateHasher> states;
//            auto inserted = states.insert(std::move(initialState));
//
//            std::vector<const State*> table;
//            table.push_back(&(*inserted.first));
//
//            inserted.first->findNextStates(table, rules, rulesByCategory, states);
//
//            LOG() << "Parser action table completed. " << table.size() << " rules created." << LOG_END;
//
//            std::cout << std::endl << "   $   c   d   S'  S   C" << std::endl;
//            std::cout << std::left;
//            int rc = 0;
//            for(auto& row: table) {
//                std::cout << std::setw(2) << rc++ << " ";
//                for (auto& e: row->mActionTableRow) {
//                    switch (e.mAction) {
//                        case REDUCE:
//                            std::cout << "r" << std::setw(2) << e.mActionPointer << " ";
//                            break;
//                        case SHIFT:
//                            std::cout << "s" << std::setw(2) << e.mActionPointer << " ";
//                            break;
//                        case ACCEPT:
//                            std::cout << "acc ";
//                            break;
//                        case GOTO:
//                            std::cout << "g" << std::setw(2) << e.mActionPointer << " ";
//                            break;
//                        case NA:
//                            std::cout << "... ";
//                            break;
//                    }
//                }
//                std::cout << std::endl;
//            }
//            std::cout << std::right;
//
//            std::vector<Symbol> tokens;
//            tokens.push_back(END);
//            tokens.push_back(d);
//            tokens.push_back(d);
//            tokens.push_back(c);
//
//            std::vector<int> stack;
//            stack.push_back(0);
//            std::vector<int> out;
//
//            bool accepted = false;
//            while (!accepted) {
//                auto& curr = tokens.back();
//                auto& act = table[stack.back()]->mActionTableRow[curr.mcId];
//                switch (act.mAction) {
//                    case REDUCE:
//                        for (int i = 0; i < rules[act.mActionPointer].mcPrd.size(); i++) {
//                            stack.pop_back();
//                        }
//                        stack.push_back(table[stack.back()]->mActionTableRow[rules[act.mActionPointer].mcCat->mcId].mActionPointer);
//                        out.push_back(rules[act.mActionPointer].mcCat->mcId);
//                        break;
//                    case SHIFT:
//                        tokens.pop_back();
//                        stack.push_back(act.mActionPointer);
//                        out.push_back(curr.mcId);
//                        break;
//                    case ACCEPT:
//                        accepted = true;
//                        break;
//                    case GOTO:
//                        LOG_ERR() << "err (goto)" << LOG_END;
//                        break;
//                    case NA:
//                        LOG_ERR() << "err (na)" << LOG_END;
//                        break;
//                }
//            }
//
//            std::stringstream ss;
//            for (auto& e: out) {
//                switch(e) {
//                    case 0:
//                        ss << "$ ";
//                        break;
//                    case 1:
//                        ss << "c ";
//                        break;
//                    case 2:
//                        ss << "d ";
//                        break;
//                    case 4:
//                        ss << "S ";
//                        break;
//                    case 3:
//                        ss << "S' ";
//                        break;
//                    case 5:
//                        ss << "C ";
//                        break;
//                    default:
//                        LOG_ERR() << "Invalid out (" << e << ")." << LOG_END;
//                }
//            }
//            LOG() << "Parser result \"c d d $\": " << ss.str() << LOG_END;
//        }
    };
}
#endif //USIDE_SRC_PARSER_H_PARSER_H
