cmake_minimum_required(VERSION 3.5)
project(ConwayGoL)

set(CMAKE_CXX_STANDARD 11)

if(WIN32)
	include_directories("C:/Users/Jack Hodgkiss/Documents/Programming/Libraries/SFML-2.4.2/include/")
	link_directories("C:/Users/Jack Hodgkiss/Documents/Programming/Libraries/SFML-2.4.2/lib")
endif(WIN32)

set(SOURCE_FILES "Source Files/main.cpp" "Source Files/World.cpp" "Header Files/World.h" "Source Files/Cell.cpp" "Header Files/Cell.h")
add_executable(ConwayGoL ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-window)

if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory "C:/Users/Jack Hodgkiss/Documents/Programming/Libraries/SFML-2.4.2/bin" ${CMAKE_BINARY_DIR})
endif(WIN32)

