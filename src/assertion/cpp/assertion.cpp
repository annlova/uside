//
// Created by Anton on 2021-05-12.
//

#include "../h/assertion.h"

#include <log/include/log_include.h>

void assertion::outputAssertion(const char* message, const char* condition, const char* pathName, const char* fileName, const char* functionName, long lineNumber){
    LOG_FTL() << "Assertion failed:"           << LOG_NL
              << "Message:   " << message      << LOG_NL
              << "Condition: " << condition    << LOG_NL
              << "Path:      " << pathName     << LOG_NL
              << "File:      " << fileName     << LOG_NL
              << "Function:  " << functionName << LOG_NL
              << "Line:      " << lineNumber   << LOG_END;
}

void assertion::outputGlAssertion(GLenum error, const char* pathName, const char* fileName, const char* functionName, long lineNumber) {
    const char* errorMessage = nullptr;

    // Parse error code
    switch (error) {
        case GL_INVALID_ENUM:
            errorMessage = "Invalid enum (GL_INVALID_ENUM).";
            break;
        case GL_INVALID_VALUE:
            errorMessage = "Invalid value (GL_INVALID_VALUE).";
            break;
        case GL_INVALID_OPERATION:
            errorMessage = "Invalid operation (GL_INVALID_OPERATION).";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            errorMessage = "Invalid framebuffer operation (GL_INVALID_FRAMEBUFFER_OPERATION).";
            break;
        case GL_OUT_OF_MEMORY:
            errorMessage = "Out of memory (GL_OUT_OF_MEMORY).";
            break;
        case GL_STACK_UNDERFLOW:
            errorMessage = "Stack underflow (GL_STACK_UNDERFLOW).";
            break;
        case GL_STACK_OVERFLOW:
            errorMessage = "Stack overflow (GL_STACK_OVERFLOW).";
            break;
        default:
            errorMessage = "Unknown error!";
    }

    LOG_FTL() << "Assertion failed:"             << LOG_NL
              << "Message:    "  << errorMessage << LOG_NL
              << "Error code: "  << error        << LOG_NL
              << "Path:       "  << pathName     << LOG_NL
              << "File:       "  << fileName     << LOG_NL
              << "Function:   "  << functionName << LOG_NL
              << "Line:       "  << lineNumber   << LOG_END;
}