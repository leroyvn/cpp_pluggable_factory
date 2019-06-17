cmake_minimum_required(VERSION 3.14)
project(cpp_pluggable_factory)

set(CMAKE_CXX_STANDARD 14)

## Simple executable-only build process
#add_executable(cpp_pluggable_factory
#    main.cpp
#    Shape.h
#    ShapeFactory.h
#    ShapeFactory.cpp
#    Circle.cpp
#    Rectangle.cpp)

# Library-based version of the build process
add_executable(cpp_pluggable_factory
    main.cpp)

add_library(libshape SHARED
    Shape.h
    ShapeFactory.h
    ShapeFactory.cpp)
# Problem: setting the lib to STATIC will disable static initialisation
# This is a typical static initialisation issue: the compiler optimises out
# our unused static variables
# Explanation here: https://meowni.ca/posts/static-initializers/

target_sources(libshape PRIVATE
    Circle.cpp)

target_sources(libshape PRIVATE
    Rectangle.cpp)

target_link_libraries(cpp_pluggable_factory
    libshape)
