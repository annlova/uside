//
// Created by Anton on 2021-05-24.
//

#include "../h/log_buffer.h"

#include <string>

#include <configs/log_config.h>

void logs::LogBuffer::setTitle(const std::string& title) {
    resetStream();
    mStream << title;
}

logs::LogBuffer::int_type logs::LogBuffer::overflow(int_type c) {
    if (traits_type::eq_int_type(traits_type::eof(), c)) {
        return traits_type::eof();
    }

    if (c == static_cast<char_type>('}')) {
        return c;
    }

    switch (c) {
        case '\n':
        case '\r':
            onNewLine(c);
            break;
        case 3:
            onTextEnd();
            break;
        default:
            mStream << static_cast<char_type>(c);
    }

    return traits_type::not_eof(c);
}

void logs::LogBuffer::onNewLine(int_type c) {
    std::basic_string<char_type> text(mStream.str());
    static_cast<void>(mBuffer->sputn(text.c_str(), text.size()));
    static_cast<void>(mBuffer->sputc(c));
    resetStream();
    mStream << std::string(gcLogTitleColumnWidth, static_cast<char_type>(' '));
}

void logs::LogBuffer::onTextEnd() {
    std::basic_string<char_type> text(mStream.str());
    static_cast<void>(mBuffer->sputn(text.c_str(), text.size()));
    static_cast<void>(mBuffer->sputc('\n'));
    static_cast<void>(mBuffer->pubsync());
}

void logs::LogBuffer::resetStream() {
    mStream.str(std::string());
    mStream.clear();
}

