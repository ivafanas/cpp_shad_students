cmake_minimum_required (VERSION 3.1)

project(hash)

#
# library with common functions for tests and exe
#

add_library(hashlib
    src/hash.cpp
    src/hash.h)

set_target_properties(hashlib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

#
# project itself
#

add_executable(hash
    src/main.cpp)

set_target_properties(hash PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

add_dependencies(hash
    hashlib)

target_link_libraries(hash
    hashlib)

#
# unit tests
#

add_executable(hash_unittests
    src/tests/main.cpp
    src/tests/hash_unittest.cpp)

set_target_properties(hash_unittests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

target_include_directories(hash_unittests PRIVATE
    "${PROJECT_SOURCE_DIR}/src")

add_dependencies(hash_unittests
    hashlib)

target_link_libraries(hash_unittests
    hashlib)

#
# GoogleTest - find in packages or download from github and compile on-the-fly.
#

find_package(GTest)
if (GTest_FOUND)
  message(STATUS "Using installed googletest package.")

  target_include_directories(hash_unittests PRIVATE
      ${GTEST_INCLUDE_DIRS})

  target_link_libraries(hash_unittests
      ${GTEST_LIBRARIES})

else()
  message(STATUS "Fallback to googletest downloading on-the-fly.")

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

  target_include_directories(hash_unittests PRIVATE
      "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
      "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

  target_link_libraries(hash_unittests
      gtest_main)

endif()

