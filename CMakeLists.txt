cmake_minimum_required(VERSION 3.14)
project(cpp_pluggable_factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_pluggable_factory
    main.cpp
    Shape.h
    ShapeFactory.h
    ShapeFactory.cpp
    ShapeMaker.h
    ShapeMaker.cpp
    Circle.cpp
    Circle.h
    CircleMaker.h
    CircleMaker.cpp)