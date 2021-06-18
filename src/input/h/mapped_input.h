//
// Created by Anton on 2021-06-18.
//

#ifndef USIDE_SRC_INPUT_H_MAPPED_INPUT_H
#define USIDE_SRC_INPUT_H_MAPPED_INPUT_H

#include <unordered_map>

namespace input {
    struct MappedInput {
        MappedInput() = delete;

        std::unordered_map<std::uint64_t, bool> mActions;
        std::unordered_map<std::uint64_t, bool> mStates;
        std::unordered_map<std::uint64_t, double> mRanges;

        /**
         * Eats an action (sets it to false), so that the
         * action is only handled once, and returns the
         * state of the action.
         * @param action - The action to lookup.
         * @return True: If the action is activate.
         *         False: If the action is not activate.
         */
        bool eatAction(std::uint64_t action) {
            eat<bool>(action, mActions);
        }

        /**
         * Eats a state (sets it to false), so that the
         * state is only handled once, and returns the
         * state of the state.
         * @param state - The state to lookup.
         * @return True: If the state is activated.
         *         False: If the state is not activated.
         */
        bool eatState(std::uint64_t state) {
            eat<bool>(state, mStates);
        }

        /**
         * Eats a range (sets it to 0.0), so that the
         * range is only handled once, and returns the
         * state of the range.
         * @param range - The range to lookup.
         * @return The value of range.
         */
        double eatRange(std::uint64_t range) {
            eat<double>(range, mRanges);
        }

    private:
        template <class T>
        T eat(std::uint64_t key, std::unordered_map<std::uint64_t, T> map) {
            auto found = map.find(key);
            if (found == map.end()) {
                return static_cast<T>(0.0);
            } else {
                map[key] = static_cast<T>(0.0);
                return found->second;
            }
        }
    };
}

#endif //USIDE_SRC_INPUT_H_MAPPED_INPUT_H
