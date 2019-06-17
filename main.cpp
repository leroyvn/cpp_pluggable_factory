#include <iostream>
#include <sstream>

#include "ShapeMaker.h"

int main() {
    std::cout << "Pluggable Factory Test" << std::endl;

    std::cout << "Creating a Circle instance" << std::endl;
    std::stringstream s;
    s << "Circle";
    Shape* shape = ShapeMaker::new_shape(s);
    shape->do_something();
    return 0;
}