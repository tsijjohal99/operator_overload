# This project was set up on v3.21.3, although may work on earlier versions
# depending on when some of the features were introduced
cmake_minimum_required(VERSION 3.21.3)

project(operator_overload VERSION 1.0.0 LANGUAGES CXX)

# Project wide setup
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(
	operator_overload
	src/operator_overload/employee_defs.h
	src/operator_overload/main.cpp
	src/operator_overload/named_type.h
	)

target_include_directories(operator_overload PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Set the IDE structure to match the folder structure
get_target_property(sources operator_overload SOURCES)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${sources}
	)

# Set the startup project for Visual Studio
if (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT operator_overload)
endif()

