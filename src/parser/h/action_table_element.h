//
// Created by Anton on 2021-05-25.
//

#ifndef USIDE_SRC_PARSER_H_ACTION_TABLE_ELEMENT_H
#define USIDE_SRC_PARSER_H_ACTION_TABLE_ELEMENT_H

namespace parser {
    enum Action {
        REDUCE,
        SHIFT,
        ACCEPT,
        GOTO,
        NA
    };

    struct ActionTableElement {
        Action mAction;
        int mActionPointer;
    };
}
#endif //USIDE_SRC_PARSER_H_ACTION_TABLE_ELEMENT_H
