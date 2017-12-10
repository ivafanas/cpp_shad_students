cmake_minimum_required (VERSION 2.8.8)

project(render)

#
# library with common functions for tests and exe
#
add_library(renderlib
	src/figures.cpp
	src/figures.h)

set_target_properties(renderlib PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_include_directories(renderlib PRIVATE
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest/include")

#
# project itself
#
add_executable(render
	src/main.cpp)

add_dependencies(render renderlib)

set_target_properties(render PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_link_libraries(render renderlib)

target_include_directories(render PRIVATE
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest/include")


#
# unit tests
#
add_executable(render_unittests
	tests/figures_unittests.cpp
	tests/main.cpp)

set_target_properties(render_unittests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_include_directories(render_unittests PRIVATE
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest"
	"${PROJECT_SOURCE_DIR}/tests/gtest/googletest/include")

add_dependencies(render renderlib)

target_link_libraries(render_unittests renderlib)

find_package(Threads REQUIRED)
target_link_libraries(render_unittests ${CMAKE_THREAD_LIBS_INIT})
