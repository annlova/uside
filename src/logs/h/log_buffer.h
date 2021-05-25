//
// Created by Anton on 2021-05-24.
//

#ifndef USIDE_SRC_LOGS_H_LOG_BUFFER_H
#define USIDE_SRC_LOGS_H_LOG_BUFFER_H

#include <streambuf>
#include <sstream>

namespace logs {
    class LogBuffer : public std::streambuf {
    public:
        LogBuffer(std::streambuf* buffer) : mBuffer(buffer), mStream() {}

    public:
        void setTitle(const std::string& title);

    private:
        int_type overflow(int_type c) override;
        void onNewLine(int_type c);
        void onTextEnd();
        void resetStream();

    private:
        std::streambuf* mBuffer;
        std::basic_stringstream<char_type> mStream;
    };
}

#endif //USIDE_SRC_LOGS_H_LOG_BUFFER_H
