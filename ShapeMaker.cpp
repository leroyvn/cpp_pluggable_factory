//
// Created by Vincent Leroy on 2019-06-16.
//

#include "ShapeMaker.h"

ShapeMaker::ShapeMaker(std::string class_name) {
    registry.insert(std::make_pair(class_name, this));
}

Shape *ShapeMaker::new_shape(std::istream &is) {
    std::string className;
    is >> className;
    ShapeMaker *maker = (*registry.find(className)).second;
    return maker->make_shape(is);
}
