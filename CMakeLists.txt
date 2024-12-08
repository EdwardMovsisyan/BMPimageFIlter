# Minimum required version
cmake_minimum_required(VERSION 3.10)

# Project name
project(CustomMakefile LANGUAGES NONE)

# Define the output directory
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/Output)

# Custom target to create Output folder and compile the program
add_custom_target(main ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}
    COMMAND g++ -std=c++11
        ${CMAKE_SOURCE_DIR}/BMPImporter.hpp
        ${CMAKE_SOURCE_DIR}/BMPExporter.hpp
        ${CMAKE_SOURCE_DIR}/Matrix.hpp
        ${CMAKE_SOURCE_DIR}/Pixel.hpp
        ${CMAKE_SOURCE_DIR}/Point.hpp
        ${CMAKE_SOURCE_DIR}/Constants.hpp
        ${CMAKE_SOURCE_DIR}/Colorfilter.hpp
        ${CMAKE_SOURCE_DIR}/Geometry.hpp
        ${CMAKE_SOURCE_DIR}/Webcam.cpp
        ${CMAKE_SOURCE_DIR}/Main.cpp
        -o ${OUTPUT_DIR}/test
    COMMENT "Compiling program and placing executable in ${OUTPUT_DIR}"
)

# Custom target for cleaning up (changed name from clean to custom_clean)
add_custom_target(custom_clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMENT "Cleaning Output folder and Makefile"
)

# Make the custom_clean target run when the user types 'make clean'
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${CMAKE_BINARY_DIR}/Makefile;${CMAKE_BINARY_DIR}/Output")

