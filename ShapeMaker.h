//
// Created by Vincent Leroy on 2019-06-16.
//

#ifndef CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H
#define CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H

#include <istream>
#include <string>
#include <map>
#include "Shape.h"

class ShapeMaker {
  public:
    static Shape *new_shape(std::istream &is);

  protected:
    typedef std::map<std::string, ShapeMaker *> MakerMap;
    virtual Shape *make_shape(std::istream &is) const = 0;
    static MakerMap registry;

    explicit ShapeMaker(std::string class_name);
};

#endif //CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H
