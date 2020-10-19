cmake_minimum_required (VERSION 3.1)

project(polynomial)


#
# Header-only library with common functions for tests and exe
#
add_library(polynomiallib INTERFACE)

target_include_directories(polynomiallib INTERFACE
    "${PROJECT_SOURCE_DIR}/src/polynomiallib")

# setup sources to display in IDE (optional)
target_sources(polynomiallib INTERFACE
    "${PROJECT_SOURCE_DIR}/src/polynomiallib/polynomial.h")


#
# project itself
#
add_executable(polynomial src/main.cpp)

set_target_properties(polynomial PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(polynomial polynomiallib)
target_link_libraries(polynomial polynomiallib)


#
# unit tests
#

# download googletest
configure_file(CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# prevent overriding the parent project's compiler/linker on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add googletest to build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(polynomial_unittests
               src/tests/main.cpp
               src/tests/polynomial_unittest.cpp)

set_target_properties(polynomial_unittests PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

target_include_directories(polynomial_unittests PRIVATE
                           "${PROJECT_SOURCE_DIR}/src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(polynomial_unittests polynomiallib)
target_link_libraries(polynomial_unittests polynomiallib gtest_main)

