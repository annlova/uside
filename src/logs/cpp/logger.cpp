//
// Created by Anton on 2021-05-12.
//

#include "../h/logger.h"

#include <thread>
#include <string_view>

const logs::Logger& logs::Logger::begin(LogSeverityLevel level, const char* file, long line) const {
    // Set console output color
    std::cout << "\033[" << gcLogSeverityLevelConsoleTextAttribute[level] << "m";

    // string view used for formatting
    std::string_view fileView(file);

    // Print logs message title
    std::cout << std::dec << "[";
    printTime();
    std::cout << "][";
    if (fileView.size() > gcLogFileTitleWidth - 3) {
        std::cout << std::left << std::setw(gcLogFileTitleWidth - 3) << fileView.substr(0, gcLogFileTitleWidth - 3) << "...";
    } else {
        std::cout << std::left << std::setw(gcLogFileTitleWidth) << fileView.substr(0, gcLogFileTitleWidth);
    }
    std::cout << std::right;
    std::cout << "][";
    std::cout << std::setw(gcLogLineTitleWidth) << line;
    std::cout << "][";
    std::cout << std::setw(gcLogThreadTitleWidth) << std::this_thread::get_id();
    std::cout << "] ";
    printSeverity(level);
    std::cout << ": ";

    return *this;
}

void logs::Logger::printSeverity(LogSeverityLevel level) {
    std::cout << std::setw(gcLogSeverityTitleWidth) << std::left;
    switch (level) {
        case FTL:
            std::cout << "FTL";
            break;
        case ERR:
            std::cout << "ERR";
            break;
        case WRN:
            std::cout << "WRN";
            break;
        case INF:
            std::cout << "INF";
            break;
        case DBG:
            std::cout << "DBG";
            break;
        case TRC:
            std::cout << "TRC";
            break;
    }
}

void logs::Logger::printTime() {
    time_t time = std::time(nullptr); // Retrieve the time and store in time variable
    if(time == -1){
        // Something went wrong, print error message
        std::cout << std::setw(gcLogTimeTitleWidth) << std::left << "Nan";
    } else {
        // Print time according to format specified by cLogTitleTimeFormat
        struct tm timeInfo{};
        errno_t error = localtime_s(&timeInfo, &time);
        if (error != 0) {
            std::cout << "ERROR   ";
        } else {
            std::cout << std::put_time(&timeInfo, gcLogTimeTitleFormat);
        }
    }
}
