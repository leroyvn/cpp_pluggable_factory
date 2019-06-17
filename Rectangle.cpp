#include <iostream>
#include "Shape.h"
#include "ShapeFactory.h"

struct Rectangle : public Shape {
    Rectangle() = default;
    ~Rectangle() override = default;

    void do_something() override {
        std::cout << "I am a Rectangle" << std::endl;
    }
};

// Self-registering factory code
class RectangleFactory : public ShapeFactory {
  private:
    RectangleFactory() : ShapeFactory("Rectangle") {}
    Shape *make_shape(std::istream &is) const override;
    std::unique_ptr<Shape> make_shape_unique(std::istream &is) const override;
    static const RectangleFactory register_this;
};

// Construct Rectangle from stream
Shape *RectangleFactory::make_shape(std::istream &is) const {
    return new Rectangle();
}

std::unique_ptr<Shape> RectangleFactory::make_shape_unique(std::istream &is) const {
    return std::make_unique<Rectangle>();
}

// Static initialisation
const RectangleFactory RectangleFactory::register_this;
