//
// Created by Anton on 2021-05-12.
//
// This file defines macros to create a "smart" enum. A
// "smart" enum, here, means an enum with values, a function
// for getting the enum by string and a function for vice
// versa.
//
// A smart enum is created by declaring SMARTENUM_HEADER in
// a header file with the parameters, typeName (name of enum)
// and values (a macro that the user defines with the enum
// values).
//
// The values parameter macro should look as such:
// #define <TYPENAME>_LIST(M, typeName) \
//    M(typeName, <VALUE1>) \
//    M(typeName, <VALUE2>) \
//    ...
//
// Where <TYPENAME> is the name of the enum and <VALUEX> is
// whatever values should be contained within the enum.
//
// Next in a corresponding cpp file SMARTENUM_CODE should be
// declared with the parameters, nameSpace (the namespace
// the corresponding SMARTENUM_HEADER was declared in),
// typeName (same as before) and values (same as before)
//
// Once a "smart" enum has been created you can use the macros
// SMARTENUM_GET_STRING to get the name of an enum value in
// string form, and SMARTENUM_GET_ENUM to get an enum value
// from its name in string form.
//

#ifndef USIDE_SRC_GLOBALS_SMART_ENUM_MACRO_H
#define USIDE_SRC_GLOBALS_SMART_ENUM_MACRO_H

#include <assertion/include/assertion_include.h>

#define SMARTENUM_VALUE(typeName, value) typeName##_##value,

#define SMARTENUM_DEFINE_ENUM(typeName, values) \
    enum typeName : unsigned int {values(SMARTENUM_VALUE, typeName) typeName##_Count, e##typeName##_Undefined};

#define SMARTENUM_STRING(typeName, value) #value,

#define SMARTENUM_DEFINE_NAMES_HEADER(typeName, values) \
    extern const char* typeName##Array[];

#define SMARTENUM_DEFINE_NAMES_CODE(nameSpace, typeName, values) \
    const char* nameSpace::typeName##Array[] = {values(SMARTENUM_STRING, typeName)};

#define SMARTENUM_DEFINE_GET_ENUM_BY_NAME_HEADER(typeName, value) \
    extern int typeName##_custom_strcmp(const char* str1, const char* str2); \
    extern typeName get##typeName##ByName(const char* str);

#define SMARTENUM_DEFINE_GET_ENUM_BY_NAME_CODE(nameSpace, typeName, value) \
    int nameSpace::typeName##_custom_strcmp(const char* str1, const char* str2){ \
        ASSERT(str1 != nullptr); \
        ASSERT(str2 != nullptr); \
        while(*str1 && *str1 == *str2) { str1++; str2++; } \
        return (unsigned char) (*str1) - (unsigned char) (*str2); \
    } \
    nameSpace::typeName nameSpace::get##typeName##ByName(const char* str){ \
        ASSERT(str != nullptr); \
        for(int i = 0; i < typeName##_Count; i++){ \
            if(typeName##_custom_strcmp(typeName##Array[i], str) == 0){ \
                return (typeName) i; \
            } \
        } \
        return e##typeName##_Undefined; \
    }

#define SMARTENUM_GET_STRING(typeName, value) typeName##Array[value]

#define SMARTENUM_GET_ENUM(typeName, name) get##typeName##ByName(name)

#define SMARTENUM_HEADER(typeName, values) \
    SMARTENUM_DEFINE_ENUM(typeName, values) \
    SMARTENUM_DEFINE_NAMES_HEADER(typeName, values) \
    SMARTENUM_DEFINE_GET_ENUM_BY_NAME_HEADER(typeName, values)

#define SMARTENUM_CODE(nameSpace, typeName, values) \
    SMARTENUM_DEFINE_NAMES_CODE(nameSpace, typeName, values) \
    SMARTENUM_DEFINE_GET_ENUM_BY_NAME_CODE(nameSpace, typeName, values)

#endif //USIDE_SRC_GLOBALS_SMART_ENUM_MACRO_H
