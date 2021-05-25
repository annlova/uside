cmake_minimum_required(VERSION 3.19)
project(uside)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(uside ${SOURCE_FILES})

set(source_dir "${CMAKE_SOURCE_DIR}/res")
set(dest_dir "${CMAKE_BINARY_DIR}/res")

## Copy changed files from res to the binary folder
add_custom_target(
        copy_res_directory ALL
        COMMAND ${CMAKE_COMMAND}
        -D src_dir=${source_dir}
        -D dst_dir=${dest_dir}
        -P "${CMAKE_SOURCE_DIR}/cmake/update_directory.cmake"
        COMMENT "Copy res directory to build tree"
        VERBATIM
)

add_dependencies(uside copy_res_directory)

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
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

##########    PROJECT SETUP    #########
target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)