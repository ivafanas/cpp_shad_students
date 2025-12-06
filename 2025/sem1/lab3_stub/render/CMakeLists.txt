cmake_minimum_required (VERSION 3.1)

project(render)

#
# library with common functions for tests and exe
#

add_library(renderlib
    src/figure.cpp)

set_target_properties(renderlib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

#
# project itself
#

add_executable(render
    src/main.cpp)

set_target_properties(render PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

add_dependencies(render
    renderlib)

target_link_libraries(render
    renderlib)

#
# unit tests
#

add_executable(render_unittests
    src/tests/main.cpp
    src/tests/render_unittests.cpp)

set_target_properties(render_unittests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

target_include_directories(render_unittests PRIVATE
    "${PROJECT_SOURCE_DIR}/src")

add_dependencies(render_unittests
    renderlib)

target_link_libraries(render_unittests
    renderlib)

#
# GoogleTest - find in packages or download from github and compile on-the-fly.
#

find_package(GTest)
if (GTest_FOUND)
  message(STATUS "Using installed googletest package.")

  target_include_directories(render_unittests PRIVATE
      ${GTEST_INCLUDE_DIRS})

  target_link_libraries(render_unittests
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

  target_include_directories(render_unittests PRIVATE
      "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
      "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

  target_link_libraries(render_unittests
      gtest_main)

endif()

#
# integration_tests target
#
add_custom_target(integration_tests
    COMMAND bash ${CMAKE_SOURCE_DIR}/run_integration_tests.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Run integration tests"
)
