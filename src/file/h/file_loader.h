//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_FILE_H_FILE_LOADER_H
#define USIDE_SRC_FILE_H_FILE_LOADER_H

#include <cstddef>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <filesystem>

#include <logs/include/log_include.h>

#include "file_flags.h"

namespace file {
    class FileLoader {
    public:
        static std::string readText(const char* path) {
            std::ifstream input(path, std::ios::in);

            if (input.is_open()) {
                std::stringstream buffer;
                buffer << input.rdbuf();
                input.close();

                return buffer.str();
            } else {
                LOG_ERR() << "Unable to open \"" << path << "\" for reading." << LOG_END;
            }

            return "";
        }

        static std::vector<std::byte> readBinary(const char* path) {
            std::ifstream input(path, std::ios::in | std::ios::binary);

            if (input.is_open()) {
                auto initialFilePosition = input.tellg();
                input.seekg(0, std::ios::end);
                auto fileSize = input.tellg() - initialFilePosition;
                input.seekg(initialFilePosition);

                std::vector<std::byte> bytes(fileSize);
                std::transform((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()), bytes.begin(), [](char c) { return std::byte(c); });

                input.close();

                return bytes;
            } else {
                LOG_ERR() << "Unable to open \"" << path << "\" for reading." << LOG_END;
            }

            return std::vector<std::byte>();
        }

        static bool createDirectories(const std::string& path) {
            auto pathDirStringLength = path.find_last_of('/') + 1;
            std::string pathDirString = path.substr(0, pathDirStringLength);
            return std::filesystem::create_directories(pathDirString);
        }

        static void writeText(const char* path, const char* data, WriteFlag flags) {
            std::ofstream outputFile(path, std::ios::out | static_cast<std::ios::openmode>(flags));

            if(outputFile.is_open()) {
                outputFile << data;
                outputFile.close();
            } else {
                auto created = createDirectories(path);
                if (created) {
                    std::ofstream outputFile2(path, std::ios::out | static_cast<std::ios::openmode>(flags));
                    if(outputFile2.is_open()) {
                        outputFile2 << data;
                        outputFile2.close();
                    } else {
                        LOG_ERR() << "Unable to open \"" << path << "\" for writing." << LOG_END;
                    }
                } else {
                    LOG_ERR() << "Unable to create directories for \"" << path << "\"." << LOG_END;
                }
            }
        }

        static void writeBinary(const char* path, const std::byte* data, WriteFlag flags) {
            std::ofstream outputFile(path, std::ios::out | std::ios::binary | static_cast<std::ios::openmode>(flags));

            if(outputFile.is_open()) {
                outputFile << data;
                outputFile.close();
            } else {
                auto created = createDirectories(path);
                if (created) {
                    std::ofstream outputFile2(path, std::ios::out | std::ios::binary | static_cast<std::ios::openmode>(flags));
                    if(outputFile2.is_open()) {
                        outputFile2 << data;
                        outputFile2.close();
                    } else {
                        LOG_ERR() << "Unable to open \"" << path << "\" for writing." << LOG_END;
                    }
                } else {
                    LOG_ERR() << "Unable to create directories for \"" << path << "\"." << LOG_END;
                }
            }
        }
    };
}
#endif //USIDE_SRC_FILE_H_FILE_LOADER_H
