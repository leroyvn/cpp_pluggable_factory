#include "CircleMaker.h"

// Construct Circle from stream
Shape *CircleMaker::make_shape(std::istream &is) const {
    return new Circle();
}

// Static initialisation
const CircleMaker  __unused CircleMaker::register_this;
