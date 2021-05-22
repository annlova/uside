//
// Created by Anton on 2021-05-12.
//
// This file defines the assert macros that should be used
// throughout the program when wanting to do an assert.
//
// The asserts will not be active if DEBUG is not defined.
//
// ASSERT_MSG Enables specifying a message to go along with
// the assertion condition.

#ifndef USIDE_SRC_ASSERTION_H_ASSERTION_MACRO_H
#define USIDE_SRC_ASSERTION_H_ASSERTION_MACRO_H

#include <glad/glad.h>
#include <debugbreak.h>

#include <configs/assertion_config.h>

#include "assertion.h"

#define USIDE_ASSERT_MACRO_FILENAME (__builtin_strrchr(__FILE__, '\\') ? __builtin_strrchr(__FILE__, '\\') + 1 : __builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

#if USIDE_WITH_FEATURE_ASSERT()
    #define ASSERT_MSG(arg, msg) do{if(!(arg)){assertion::outputAssertion(msg, #arg, __FILE__, USIDE_ASSERT_MACRO_FILENAME, __PRETTY_FUNCTION__, __LINE__); debug_break();}} while(false) // NOLINT cppcoreguidelines-pro-bounds-pointer-arithmetic
    #define ASSERT(arg) do{if(!(arg)){assertion::outputAssertion("Assertion!", #arg, __FILE__, USIDE_ASSERT_MACRO_FILENAME, __PRETTY_FUNCTION__, __LINE__); debug_break();}} while(false) // NOLINT cppcoreguidelines-pro-bounds-pointer-arithmetic
    #define ASSERT_GL() do{const GLenum _____uside_assert_macro_gl_error_enum_____ = glGetError();if(_____uside_assert_macro_gl_error_enum_____){assertion::outputGlAssertion((_____uside_assert_macro_gl_error_enum_____), __FILE__, USIDE_ASSERT_MACRO_FILENAME, __PRETTY_FUNCTION__, __LINE__);debug_break();}} while(false) // NOLINT cppcoreguidelines-pro-bounds-pointer-arithmetic
    #define ASSERT_GL_CODE(glError) do{const GLenum _____uside_assert_macro_gl_error_enum_____ = glError;if(_____uside_assert_macro_gl_error_enum_____){assertion::outputGlAssertion((_____uside_assert_macro_gl_error_enum_____), __FILE__, USIDE_ASSERT_MACRO_FILENAME, __PRETTY_FUNCTION__, __LINE__);debug_break();}} while(false) // NOLINT cppcoreguidelines-pro-bounds-pointer-arithmetic
#else // Assertions disabled
    #define ASSERT_MSG(arg, msg) do { (void) sizeof((arg)), (void) sizeof((msg)); } while(false)
    #define ASSERT(arg)          do { (void) sizeof((arg)); } while(false)
    #define ASSERT_GL(glError)   do { (void) sizeof((glError)); } while(false)
#endif

#endif //USIDE_SRC_ASSERTION_H_ASSERTION_MACRO_H
