cmake_minimum_required(VERSION 3.19)
project(uside)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(uside ${SOURCE_FILES})

##########    DEBUG_BREAK    ##########
set(DEBUG_BREAK_DIR "${CMAKE_SOURCE_DIR}/libraries/debug_break")
target_include_directories(${PROJECT_NAME} PRIVATE ${DEBUG_BREAK_DIR}/include)

##########    GLFW    ##########
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/libraries/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

##########    GLAD    ##########
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/libraries/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c" src/shader/include/shader_include.h src/shader/h/shader_program_factory.h src/shader/h/attribute.h src/shader/h/uniform.h src/shader/cpp/uniform.cpp src/shader/h/image.h src/shader/cpp/image.cpp src/shader/h/sampler.h src/shader/cpp/sampler.cpp src/shader/h/shader_block.h src/shader/h/active_variable.h src/shader/cpp/shader_block.cpp src/shader/h/uniform_type.h src/shader/h/shader_program_resource_factory.h src/shader/cpp/shader_program_resource_factory.cpp src/string/h/string_hash_crc64.h src/string/include/string_hash_include.h src/shader/h/shader_program.h src/shader/cpp/shader_program.cpp src/file/h/file_flags.h src/file/h/file_loader.h src/file/include/file_include.h)
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)