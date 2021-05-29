//
// Created by Anton on 2021-05-25.
//

#ifndef USIDE_SRC_PARSER_H_PARSER_H
#define USIDE_SRC_PARSER_H_PARSER_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <bnf/bnf_include.h>

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
        void printOutShift(const Token& t, const std::unordered_map<int, std::string>& idToString, const std::vector<Symbol>& symbols, int num) {
            auto type = symbols[t.mId].mcType;
            switch (type) {
                case STRING:
                    LOG() << idToString.at(t.mId) << " " << num << " (\"" << static_cast<const char*>(t.mData) << "\")" << LOG_END;
                    break;
                case CHAR:
                    LOG() << idToString.at(t.mId) << " " << num << " (\'" << *reinterpret_cast<const char*>(&t.mData) << "\')" << LOG_END;
                    break;
                case INT:
                    LOG() << idToString.at(t.mId) << " " << num << " (" << *reinterpret_cast<const int*>(&t.mData) << ")" << LOG_END;
                    break;
                case NONE:
                    LOG() << idToString.at(t.mId) << " " << num << " (void)" << LOG_END;
                    break;
            }
        }
        void printOutToken(const Token& t, const std::unordered_map<int, std::string>& idToString, const std::vector<Symbol>& symbols, int num) {
            auto type = symbols[t.mId].mcType;
            switch (type) {
                case STRING:
                    LOG_DBG() << idToString.at(t.mId) << " " << num << " (\"" << static_cast<const char*>(t.mData) << "\")" << LOG_END;
                    break;
                case CHAR:
                    LOG_DBG() << idToString.at(t.mId) << " " << num << " (\'" << *reinterpret_cast<const char*>(&t.mData) << "\')" << LOG_END;
                    break;
                case INT:
                    LOG_DBG() << idToString.at(t.mId) << " " << num << " (" << *reinterpret_cast<const int*>(&t.mData) << ")" << LOG_END;
                    break;
                case NONE:
                    LOG_DBG() << idToString.at(t.mId) << " " << num << " (void)" << LOG_END;
                    break;
            }
        }
        void printOutReduce(const Token& t, const std::unordered_map<int, std::string>& idToString, const std::vector<Symbol>& symbols, int num) {
            auto type = symbols[t.mId].mcType;
            switch (type) {
                case STRING:
                    LOG_TRC() << idToString.at(t.mId) << " " << num << " (\"" << static_cast<const char*>(t.mData) << "\")" << LOG_END;
                    break;
                case CHAR:
                    LOG_TRC() << idToString.at(t.mId) << " " << num << " (\'" << *reinterpret_cast<const char*>(&t.mData) << "\')" << LOG_END;
                    break;
                case INT:
                    LOG_TRC() << idToString.at(t.mId) << " " << num << " (" << *reinterpret_cast<const int*>(&t.mData) << ")" << LOG_END;
                    break;
                case NONE:
                    LOG_TRC() << idToString.at(t.mId) << " " << num << " (void)" << LOG_END;
                    break;
            }
        }

        Parser () {
            auto parserInfoPathPath = "res/parser/parser_info_path_temp.txt";
            auto SourceCodePathPath = "res/parser/bnf_path_temp.txt";
            auto parserInfoPath = file::FileLoader::readText(parserInfoPathPath);
            auto sourceCodePath = file::FileLoader::readText(SourceCodePathPath);
            auto parserInfo = file::FileLoader::readText(parserInfoPath.c_str());
            auto sourceCode = file::FileLoader::readText(sourceCodePath.c_str());

            Tokenizer tokenizer(parserInfo);
            tokenizer.loadSourceCode(sourceCode);

            auto& idToString = tokenizer.getSymbolIdToNameMap();
            auto& symbols = tokenizer.getSymbols();
            auto& rules = tokenizer.getRules();
            auto& rulesByCategory = tokenizer.getRulesByCategory();

            RuleItem initialStateRuleItem(rules, rules.size() - 1, 0, &symbols[gcEofSymbolId]);
            State initialState(0, symbols.size());
            initialState.mItems.insert(initialStateRuleItem);
            for(auto& e: initialState.mActionTableRow) {
                e.mAction = Action::NA;
                e.mActionPointer = -1;
            }

            initialState.closure(rules, rulesByCategory);

            std::unordered_set<State, StateHasher> states;
            auto inserted = states.insert(std::move(initialState));

            std::vector<const State*> table;
            table.push_back(&(*inserted.first));

            inserted.first->findNextStates(table, rules, rulesByCategory, states);

            LOG() << "Parser action table completed. " << table.size() << " states created." << LOG_END;

            LOG() << "Attempting to parse \"" << sourceCodePath << "\"..." << LOG_END;
            std::stack<std::pair<int, Token>> stack;
            Token t(0, nullptr);
            stack.push(std::make_pair(initialState.mcId, t));
            std::vector<Token> out;

            auto lookahead = tokenizer.next();
//            printOutToken(token, idToString, symbols, -1);
            bool accepted = false;
            while (!accepted) {
                auto action = table[stack.top().first]->mActionTableRow[lookahead.mId];
                bool emptyWordRead = false;
                if (action.mAction == Action::NA) {
                    action = table[stack.top().first]->mActionTableRow[gcEmptyWordSymbolId];
                    emptyWordRead = true;
                }
                switch (action.mAction) {
                    case REDUCE: {
                        auto& rule = rules[action.mActionPointer];
                        int dataSize = rule.mNumActiveDataFlags + 1;
                        void** data = new void*[dataSize]; // + 1 for vtable pointer
                        auto& prds = rule.mcPrd;
                        auto& dataFlags = rule.mcPrdDataFlags;
                        int numDataPointersFilled = 0;
                        for (int i = prds.size() - 1; i >= 0; i--) {
                            if (dataFlags[i]) {
                                auto* temp = stack.top().second.mData;
                                LOG_DBG() << idToString.at(stack.top().second.mId) << LOG_END;
                                auto a = static_cast<char*>(temp);
                                auto b = static_cast<int>(reinterpret_cast<std::intptr_t>(temp));
                                data[dataSize - 1 - numDataPointersFilled] = temp;
                                numDataPointersFilled++;
                            }
                            stack.pop();
                        }
                        int vtableId = rule.mcVTableId;
                        ASSERT(vtableId > -1);
                        data[0] = absyn::bnf::getVTablePtr(static_cast<absyn::bnf::AbsynBnfClasses>(vtableId));
//                        auto& tok = out.emplace_back(rules[action.mActionPointer].mcCat->mcId, data);
//                        t = new Token(rules[action.mActionPointer].mcCat->mcId, nullptr);
//                        printOutReduce(*t, idToString, symbols, action.mActionPointer);
//                        delete t;
                        Token tok(rule.mcCat->mcId, data);
                        LOG() << idToString.at(lookahead.mId) << LOG_END;
                        stack.push(std::make_pair(table[stack.top().first]->mActionTableRow[rule.mcCat->mcId].mActionPointer, tok));
                    }
                        break;
                    case SHIFT:
                        if (emptyWordRead) {
                            Token tok(gcEmptyWordSymbolId, nullptr);
                            stack.push(std::make_pair(action.mActionPointer, tok));
                            LOG_TRC() << idToString.at(stack.top().second.mId) << LOG_END;
//                            t = new Token(gcEmptyWordSymbolId, nullptr);
//                            printOutShift(*t, idToString, symbols, action.mActionPointer);
//                            delete t;
                        } else {
                            stack.push(std::make_pair(action.mActionPointer, lookahead));
//                            out.push_back(token);
//                            printOutShift(token, idToString, symbols, action.mActionPointer);
                            lookahead = tokenizer.next();
                            LOG_TRC() << idToString.at(stack.top().second.mId) << LOG_END;
//                            printOutToken(token, idToString, symbols, action.mActionPointer);
                        }
                        break;
                    case ACCEPT:
                        accepted = true;
                        break;
                    case GOTO:
                        ASSERT_MSG(false, "GOTO");
                        break;
                    case NA:
                        ASSERT_MSG(false, "NA");
                        break;
                }
            }

            LOG() << "Parsing complete. Output:" << LOG_END;

            absyn::bnf::Grammar* grammar = reinterpret_cast<absyn::bnf::Grammar*>(stack.top().second.mData);
            LOG() << "Did this actually work?" << LOG_END;
            delete grammar;

//            for (auto& t: out) {
//                auto type = symbols[t.mId].mcType;
//                switch (type) {
//                    case STRING:
//                        LOG() << idToString.at(t.mId) << " (\"" << static_cast<const char*>(t.mData) << "\")" << LOG_END;
//                        break;
//                    case CHAR:
//                        LOG() << idToString.at(t.mId) << " (\'" << *reinterpret_cast<const char*>(&t.mData) << "\')" << LOG_END;
//                        break;
//                    case INT:
//                        LOG() << idToString.at(t.mId) << " (" << *reinterpret_cast<const int*>(&t.mData) << ")" << LOG_END;
//                        break;
//                    case NONE:
//                        LOG() << idToString.at(t.mId) << " (void)" << LOG_END;
//                        break;
//                }
//            }
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
//                auto& act = table[stack.back()]->mActionTableRow[curr.mId];
//                switch (act.mAction) {
//                    case REDUCE:
//                        for (int i = 0; i < rules[act.mActionPointer].mcPrd.size(); i++) {
//                            stack.pop_back();
//                        }
//                        stack.push_back(table[stack.back()]->mActionTableRow[rules[act.mActionPointer].mcCat->mId].mActionPointer);
//                        out.push_back(rules[act.mActionPointer].mcCat->mId);
//                        break;
//                    case SHIFT:
//                        tokens.pop_back();
//                        stack.push_back(act.mActionPointer);
//                        out.push_back(curr.mId);
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
