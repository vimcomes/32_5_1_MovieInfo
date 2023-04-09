cmake_minimum_required(VERSION 3.23)
project(32_5_1_MovieInfo)
set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(32_5_1_MovieInfo main.cpp)

target_link_libraries(32_5_1_MovieInfo PRIVATE nlohmann_json::nlohmann_json)
