#include <iostream>
#include <sstream>

#include "ShapeMaker.h"

int main() {
    std::stringstream s;
    s << "Circle";
    Shape* shape = ShapeMaker::new_shape(s);
    shape->do_something();
    return 0;
}