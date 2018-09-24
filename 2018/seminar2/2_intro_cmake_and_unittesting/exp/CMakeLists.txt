cmake_minimum_required (VERSION 2.8.8)

project(exponent)


#
# library with common functions for tests and exe
#
add_library(explib
        src/explib/solver.cpp
        src/explib/solver.h
        src/explib/util.cpp
        src/explib/util.h)

set_target_properties(explib PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(exp src/main.cpp)

set_target_properties(exp PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

add_dependencies(exp explib)
target_link_libraries(exp explib)

#
# unit tests
#
add_executable(exp_unittests
        src/tests/main.cpp
	src/tests/util_unittest.cpp
	src/tests/solver_unittest.cpp)

set_target_properties(exp_unittests PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)

target_include_directories(exp_unittests PRIVATE
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/ext/googletest/googletest"
	"${PROJECT_SOURCE_DIR}/ext/googletest/googletest/include")

add_dependencies(exp_unittests explib)
target_link_libraries(exp_unittests explib)

# cheat for gtests
find_package(Threads REQUIRED)
target_link_libraries(exp_unittests ${CMAKE_THREAD_LIBS_INIT})

