#include "ShapeMaker.h"

// Register a new Maker
ShapeMaker::ShapeMaker(const std::string& class_name) {
    registry.insert(std::make_pair(class_name, this));
}

// Create a concrete instance
Shape *ShapeMaker::new_shape(std::istream &is) {
    std::string class_name;
    is >> class_name;
    ShapeMaker *maker = (*registry.find(class_name)).second;
    return maker->make_shape(is);
}

// Initialise static members
ShapeMaker::MakerMap ShapeMaker::registry;
