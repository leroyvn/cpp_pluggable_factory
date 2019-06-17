//
// Created by Vincent Leroy on 2019-06-16.
//

#ifndef CPP_PLUGGABLE_FACTORY_CIRCLEMAKER_H
#define CPP_PLUGGABLE_FACTORY_CIRCLEMAKER_H

#include "ShapeMaker.h"
#include "Circle.h"

class CircleMaker : public ShapeMaker {
  private:
    CircleMaker() : ShapeMaker("Circle") {}

    Shape* make_shape(std::istream& is) const override {
        return new Circle();
    }

    static const CircleMaker register_this;
};

#endif //CPP_PLUGGABLE_FACTORY_CIRCLEMAKER_H
