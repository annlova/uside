//
// Created by Anton on 2021-06-03.
//

#ifndef USIDE_SRC_PARSER_H_BNF_COMPILER_TERMINAL_DATA_H
#define USIDE_SRC_PARSER_H_BNF_COMPILER_TERMINAL_DATA_H

#include <string>

namespace parser {
    struct BnfCompilerTerminalData {
        std::string mName;
        std::string mCompleteRegex;
        std::string mPartialRegex;
        std::string mDataType;

        bool operator==(const BnfCompilerTerminalData& rhs) const {
            return mName == rhs.mName;
        }
    };

    struct BnfCompilerTerminalDataHasher {
        std::size_t operator()(const BnfCompilerTerminalData& data) const {
            std::hash<char> hashString;
            return hashString(*data.mName.data());
        }
    };
}

#endif //USIDE_SRC_PARSER_H_BNF_COMPILER_TERMINAL_DATA_H
