//
// Created by Anton on 2021-05-24.
//

#include "../h/rule.h"

bool parser::Rule::isReductionOf(const parser::Rule* const rule, int index) const {
    if (rule->mcPrd.size() == index) {
        for (int i = 0; i < mcPrd.size(); i++) {
            if (mcPrd[i] != rule->mcPrd[i]) {
                return false;
            }
        }

        return true;
    }

    return false;
}