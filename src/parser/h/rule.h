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
            const std::vector<const Symbol*> mcPrd;
            const std::vector<bool> mcPrdDataFlags;
            int mNumActiveDataFlags;
            const int mcVTableId;

            Rule(const int id, const Symbol* const cat, int vtableId, std::initializer_list<const Symbol*> prd, std::initializer_list<bool> prdDataFlags) : mcId(id), mcCat(cat), mcVTableId(vtableId), mcPrd(std::move(prd)), mcPrdDataFlags(std::move(prdDataFlags)), mNumActiveDataFlags(0) {
                for (auto b: mcPrdDataFlags) {
                    if (b) {
                        mNumActiveDataFlags++;
                    }
                }
            }
            Rule(const int id, const Symbol* const cat, int vtableId, std::vector<const Symbol*> prd, std::vector<bool> prdDataFlags) : mcId(id), mcCat(cat), mcVTableId(vtableId), mcPrd(std::move(prd)), mcPrdDataFlags(std::move(prdDataFlags)), mNumActiveDataFlags(0) {
                for (auto b: mcPrdDataFlags) {
                    if (b) {
                        mNumActiveDataFlags++;
                    }
                }
            }

            bool isReductionOf(const Rule* const rule, int index) const;
        };
}

#endif //USIDE_SRC_PARSER_H_RULE_H
