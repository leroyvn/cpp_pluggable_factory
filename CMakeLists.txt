cmake_minimum_required(VERSION 3.14)
project(cpp_factory)

set(CMAKE_CXX_STANDARD 14)

## Simple executable-only build process
#add_executable(cpp_factory
#    main.cpp
#    Base.h
#    Base.cpp
#    DerivedA.h
#    DerivedA.cpp
#    DerivedB.h
#    DerivedB.cpp)

# Library-based version of the build process
add_executable(cpp_factory
    main.cpp)

add_library(libbase SHARED
    Base.h
    Base.cpp
    Factory.h)
# Problem: setting the lib to STATIC will disable static initialisation
# This is a typical static initialisation issue: the compiler optimises out
# our unused static variables
# Explanation here: https://meowni.ca/posts/static-initializers/

target_sources(libbase PRIVATE
    DerivedA.h
    DerivedA.cpp)

target_sources(libbase PRIVATE
    DerivedB.h
    DerivedB.cpp)

target_link_libraries(cpp_factory
    libbase)
