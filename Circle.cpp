#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"

struct Circle : public Shape {
    Circle() = default;
    ~Circle() override = default;

    void do_something() override {
        std::cout << "I am a Circle" << std::endl;
    }
};

// Self-registering factory code
class CircleFactory : public ShapeFactory {
  private:
    CircleFactory() : ShapeFactory("Circle") {}
    Shape *make_shape(std::istream &is) const override;
    std::unique_ptr<Shape> make_shape_unique(std::istream &is) const override;
    static const CircleFactory register_this;
};

// Construct Circle from stream
Shape *CircleFactory::make_shape(std::istream &is) const {
    return new Circle();
}

std::unique_ptr<Shape> CircleFactory::make_shape_unique(std::istream &is) const {
    return std::make_unique<Circle>();
}

// Static initialisation
const CircleFactory CircleFactory::register_this;
