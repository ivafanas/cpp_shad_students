cmake_minimum_required (VERSION 2.8.8)

project (mega_incrementer)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/reader.cpp
	src/reader.h
	src/solver.cpp
	src/solver.h
	src/writer.cpp
	src/writer.h)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO)
