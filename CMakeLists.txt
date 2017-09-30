cmake_minimum_required(VERSION 3.8)
project(ConwayGoL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "Source Files/main.cpp" "Source Files/World.cpp" "Header Files/World.h" "Source Files/Cell.cpp" "Header Files/Cell.h")
add_executable(ConwayGoL ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-window)