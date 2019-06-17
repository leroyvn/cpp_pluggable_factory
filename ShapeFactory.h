//
// Created by Vincent Leroy on 2019-06-16.
//

#ifndef CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H
#define CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H

#include <istream>
#include "Circle.h"

class ShapeFactory {
  public:
    static  Shape* make_shape(std::istream &params) {
        std::string class_name;
        params >> class_name;

        if (class_name == "Circle") {
            return new Circle();
        }

        return nullptr;
    }
};

#endif //CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H
