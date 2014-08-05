project ( 2D_ENGINE )
cmake_minimum_required ( VERSION 3.0 )

# Output compiled files in root directory
set ( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/.. )
set ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/.. )

# Use C++11 standard
if ( CMAKE_CXX_COMPILER MATCHES ".*clang" )
    set ( CMAKE_COMPILER_IS_CLANG )
endif ( CMAKE_CXX_COMPILER MATCHES ".*clang" )

if ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG )
    list ( APPEND CMAKE_CXX_FLAGS "-std=c++11" )
endif ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG )

# Include headers from inc
include_directories ( ${CMAKE_SOURCE_DIR}/inc )

# Add the two subdirectories
add_subdirectory ( ${CMAKE_SOURCE_DIR}/src )
add_subdirectory ( ${CMAKE_SOURCE_DIR}/tests )
