#include <iostream>
#include "ShapeFactory.h"

// Register a new factory
ShapeFactory::ShapeFactory(const std::string& class_name) {
    registry.insert(std::make_pair(class_name, this));
}

// Display registered methods
void ShapeFactory::show_registered() {
    for (const auto& it : registry) {
        std::cout << "+ " << it.first << std::endl;
    }
}

// Create a concrete instance
Shape *ShapeFactory::new_shape(std::istream &is) {
    std::string class_name;
    is >> class_name;
    ShapeFactory *factory = (*registry.find(class_name)).second;
    return factory->make_shape(is);
}

std::unique_ptr<Shape> ShapeFactory::new_shape_unique(std::istream &is) {
    std::string class_name;
    is >> class_name;
    ShapeFactory *factory = (*registry.find(class_name)).second;
    return factory->make_shape_unique(is);
}

// Initialise static members
ShapeFactory::FactoryMap ShapeFactory::registry;
