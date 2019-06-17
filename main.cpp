#include <iostream>
#include <sstream>
#include <memory>

#include "ShapeFactory.h"

int main() {
    std::cout << "Pluggable Factory Test" << std::endl
              << std::endl;

    std::cout << "Registered classes:" << std::endl;
    ShapeFactory::show_registered();
    std::cout << std::endl;

    {
        std::cout << "Creating a Circle instance" << std::endl;
        std::stringstream s;
        s << "Circle";
        Shape *shape = ShapeFactory::new_shape(s);
        shape->do_something();
        delete shape;
    }

    std::cout << std::endl;

    {
        std::cout << "Creating a Rectangle instance" << std::endl;
        std::stringstream s;
        s << "Rectangle";
        std::unique_ptr<Shape> shape = ShapeFactory::new_shape_unique(s);
        shape->do_something();
    }

    return 0;
}
