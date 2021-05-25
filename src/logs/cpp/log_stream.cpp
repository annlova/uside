//
// Created by Anton on 2021-05-12.
//

#include "../h/log_stream.h"

#include <thread>
#include <string_view>
#include <sstream>

logs::LogStream& logs::LogStream::begin(LogSeverityLevel level, const char* file, long line) {
    std::stringstream titleStringBuilder;

    // Set console output color
    titleStringBuilder << "\033[" << gcLogSeverityLevelConsoleTextAttribute[level] << "m";

    // string view used for formatting
    std::string_view fileView(file);

    // Print logs message title
    titleStringBuilder << "[";
    appendTime(titleStringBuilder);
    titleStringBuilder << "][";
    if (fileView.size() > gcLogFileTitleWidth - 3) {
        titleStringBuilder << std::left << std::setw(gcLogFileTitleWidth - 3) << fileView.substr(0, gcLogFileTitleWidth - 3) << "...";
    } else {
        titleStringBuilder << std::left << std::setw(gcLogFileTitleWidth) << fileView.substr(0, gcLogFileTitleWidth);
    }
    titleStringBuilder << std::right;
    titleStringBuilder << "][";
    titleStringBuilder << std::setw(gcLogLineTitleWidth) << line;
    titleStringBuilder << "][";
    titleStringBuilder << std::setw(gcLogThreadTitleWidth) << std::this_thread::get_id();
    titleStringBuilder << "] ";
    appendSeverity(level, titleStringBuilder);
    titleStringBuilder << ": ";

    mLogBuffer.setTitle(titleStringBuilder.str());
    static_cast<void>(operator<<(std::dec));
    static_cast<void>(operator<<(std::boolalpha));

    return *this;
}

void logs::LogStream::appendSeverity(LogSeverityLevel level, std::stringstream& stringBuilder) {
    stringBuilder << std::setw(gcLogSeverityTitleWidth) << std::left;
    switch (level) {
        case FTL:
            stringBuilder << "FTL";
            break;
        case ERR:
            stringBuilder << "ERR";
            break;
        case WRN:
            stringBuilder << "WRN";
            break;
        case INF:
            stringBuilder << "INF";
            break;
        case DBG:
            stringBuilder << "DBG";
            break;
        case TRC:
            stringBuilder << "TRC";
            break;
    }
}

void logs::LogStream::appendTime(std::stringstream& stringBuilder) {
    time_t time = std::time(nullptr); // Retrieve the time and store in time variable
    if(time == -1){
        // Something went wrong, print error message
        stringBuilder << std::setw(gcLogTimeTitleWidth) << std::left << "Nan";
    } else {
        // Print time according to format specified by cLogTitleTimeFormat
        struct tm timeInfo{};
        errno_t error = localtime_s(&timeInfo, &time);
        if (error != 0) {
            stringBuilder << "ERROR   ";
        } else {
            stringBuilder << std::put_time(&timeInfo, gcLogTimeTitleFormat);
        }
    }
}

logs::LogStream& logs::getLogStream()  {
    static LogStream logStream;
    return logStream;
}
