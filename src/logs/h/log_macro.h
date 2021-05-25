//
// Created by Anton on 2021-05-12.
//
// This file defines the macro that should be used
// throughout the program when logging.

#ifndef USIDE_SRC_LOGS_H_LOG_MACRO_H
#define USIDE_SRC_LOGS_H_LOG_MACRO_H

#include <mutex>

#include <configs/log_config.h>

#include "log_global_mutex.h"
#include "log_stream.h"

#define USIDE_LOG_MACRO_FILENAME (__builtin_strrchr(__FILE__, '\\') ? __builtin_strrchr(__FILE__, '\\') + 1 : __builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

#if USIDE_WITH_FEATURE_LOG()
    #define LOG()       do { if(USIDE_LOG_DEFAULT_SEVERITY() <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(USIDE_LOG_DEFAULT_SEVERITY(), USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/

    #define LOG_0()     do { if(0 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::FTL, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_1()     do { if(1 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::ERR, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_2()     do { if(2 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::WRN, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_3()     do { if(3 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::INF, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_4()     do { if(4 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::DBG, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_5()     do { if(5 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::TRC, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_FTL()   do { if(0 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::FTL, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_ERR()   do { if(1 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::ERR, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_WRN()   do { if(2 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::WRN, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_INF()   do { if(3 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::INF, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_DBG()   do { if(4 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::DBG, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
    #define LOG_TRC()   do { if(5 <= USIDE_LOG_MAX_SEVERITY()) { const std::lock_guard<std::mutex> cLogGuard(logs::gLogMutex); logs::getLogStream().begin(logs::TRC, USIDE_LOG_MACRO_FILENAME, __LINE__)/* NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)*/
#else
    #define LOG()       do { if(0) { logs::gLogOutput.output(USIDE_LOG_DEFAULT_SEVERITY(), nullptr, 0L); } while(0)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/

    #define LOG_0()     do { if(0) { logs::gcLogger.begin(logs::FTL, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_1()     do { if(0) { logs::gcLogger.begin(logs::ERR, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_2()     do { if(0) { logs::gcLogger.begin(logs::WRN, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_3()     do { if(0) { logs::gcLogger.begin(logs::INF, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_4()     do { if(0) { logs::gcLogger.begin(logs::DBG, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_5()     do { if(0) { logs::gcLogger.begin(logs::TRC, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_FTL()   do { if(0) { logs::gcLogger.begin(logs::FTL, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_ERR()   do { if(0) { logs::gcLogger.begin(logs::ERR, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_WRN()   do { if(0) { logs::gcLogger.begin(logs::WRN, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_INF()   do { if(0) { logs::gcLogger.begin(logs::INF, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_DBG()   do { if(0) { logs::gcLogger.begin(logs::DBG, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
    #define LOG_TRC()   do { if(0) { logs::gcLogger.begin(logs::TRC, nullptr, 0L)/*NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)*/
#endif

#define LOG_NL  "\n"
#define LOG_DEC std::dec
#define LOG_HEX std::hex
#define LOG_NO_BOOL std::noboolalpha

#define LOG_END "\033[0m" << static_cast<char>(3);}}while(false)

#endif //USIDE_SRC_LOGS_H_LOG_MACRO_H
