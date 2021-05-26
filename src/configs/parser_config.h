//
// Created by Anton on 2021-05-26.
//

#ifndef USIDE_SRC_CONFIGS_PARSER_CONFIG_H
#define USIDE_SRC_CONFIGS_PARSER_CONFIG_H

namespace parser {
    /// Important: Must be = 0! The end-of-file token, which is always present, always has the same id.
    constexpr int gcEofSymbolId = 0;

    inline constexpr auto gcParserInfoTerminalLineIdentifier = "0";
    inline constexpr auto gcParserInfoNonTerminalLineIdentifier = "1";
    inline constexpr auto gcParserInfoRuleLineIdentifier = "2";
    inline constexpr auto gcParserInfoRuleLineProductionEndIdentifier = "2";
}

#endif //USIDE_SRC_CONFIGS_PARSER_CONFIG_H
