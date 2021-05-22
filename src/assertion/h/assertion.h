//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_ASSERTION_H_ASSERTION_H
#define USIDE_SRC_ASSERTION_H_ASSERTION_H

#include <glad/glad.h>

namespace assertion {

    /** The global assert function that is called upon
     *  ASSERT/ASSERT_MSG macro failing. It outputs
     *  formatted debug text through the LOG macro. */
    extern void outputAssertion(const char* message, const char* condition, const char* pathName, const char* fileName, const char* functionName, long lineNumber);

    /** The global assert function that is called upon
     *  ASSERT_GL macro failing. It outputs
     *  formatted debug text through the LOG macro. */
    extern void outputGlAssertion(GLenum error, const char* pathName, const char* fileName, const char* functionName, long lineNumber);

}

#endif //USIDE_SRC_ASSERTION_H_ASSERTION_H
