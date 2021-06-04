//
// Created by Anton on 2021-06-04.
//

#ifndef USIDE_SRC_INPUT_H_INPUT_LISTENER_H
#define USIDE_SRC_INPUT_H_INPUT_LISTENER_H

#include "mapped_input.h"

namespace input {
    struct InputListener {
        InputListener() = delete;

        virtual void onInputEvent(MappedInput& input) = 0;
    };
}
#endif //USIDE_SRC_INPUT_H_INPUT_LISTENER_H
