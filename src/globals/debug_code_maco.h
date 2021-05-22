//
// Created by Anton on 2021-05-12.
//
// This file defines a macro used for including/excluding
// debug code within the program. If
// USIDE_WITH_FEATURE_DEBUG_CODE() != 0, then anything
// entered within the DEBUG_CODE(X) macro will be included
// in the program. The macro is basically short hand for:
//
// #if USIDE_WITH_FEATURE_DEBUG_CODE()
//     X
// #endif
//
// OBS! Important to use the macro COMMA for comma (,) tokens
// as otherwise the preprocessor will think there are multiple
// arguments being passed.
//
// This macro does not require the use of a semicolon to
// end the statement as it needs to be insertable anywhere
// within the program.
//
#ifndef USIDE_SRC_GLOBALS_DEBUG_CODE_MACO_H
#define USIDE_SRC_GLOBALS_DEBUG_CODE_MACO_H

#include <configs/debug_code_config.h>

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    #define DEBUG_CODE(X) X
#else
    #define DEBUG_CODE(X)
#endif

// Needed to include commas in DEBUG_CODE(X) macro as normal
// commas (,) will make preprocessor think there are multiple
// parameters.
#define COMMA ,

#endif //USIDE_SRC_GLOBALS_DEBUG_CODE_MACO_H
