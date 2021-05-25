//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_PARSER_H_TOKEN_H
#define USIDE_SRC_PARSER_H_TOKEN_H

#include <cstddef>
#include <memory>

namespace parser {

        /// The end-of-file token, which is always present, always has the same id.
        constexpr int gcEofTokenId = 0;

        struct Token {
            const int mcId;
            const bool mcTerminal;
            // TODO: Store actual data

            Token(const int id, const bool terminal) : mcId(id), mcTerminal(terminal) {}

            bool operator==(const Token& other) const;
            bool operator!=(const Token& other) const;
        };

        struct TokenHasher {
            std::size_t operator()(const Token& token) const {
                return std::hash<int>()(token.mcId);
            }
        };
}

#endif //USIDE_SRC_PARSER_H_TOKEN_H
