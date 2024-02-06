# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.15)

# Project's name
project(ExcelReader)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

# Add executable target with source files listed in SOURCE_FILES variable
set(SOURCE_FILES main.cpp Services/ExcelService.cpp)
add_executable(ExcelReader ${SOURCE_FILES})



# If you have include directories
# include_directories(Services)

# If you have link directories
#link_directories(directory_name)

# If you have libraries to link
target_link_libraries(ExcelReader OpenXLSX::OpenXLSX)