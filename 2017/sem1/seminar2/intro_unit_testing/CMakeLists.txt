cmake_minimum_required (VERSION 2.8.8)

project(polylen)


#
# library with common functions for tests and exe
#
add_library(polylenlib
	src/polylen_calc.cpp
	src/polylen_calc.h)

set_target_properties(polylenlib PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(polylen
	src/main.cpp)

add_dependencies(polylen polylenlib)

set_target_properties(polylen PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_link_libraries(polylen polylenlib)

#
# unit tests
#
add_executable(polylen_unittests
	tests/main.cpp
	tests/polylen_calc_unittest.cpp)

set_target_properties(polylen_unittests PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_include_directories(polylen_unittests PRIVATE
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest/include")

add_dependencies(polylen polylenlib)

target_link_libraries(polylen_unittests polylenlib)

find_package(Threads REQUIRED)
target_link_libraries(polylen_unittests ${CMAKE_THREAD_LIBS_INIT})
