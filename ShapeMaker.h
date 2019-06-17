#ifndef CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H
#define CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H

#include <istream>
#include <string>
#include <map>
#include "Shape.h"

class ShapeMaker {
  public:
    virtual ~ShapeMaker() = default;
    static Shape *new_shape(std::istream &is);

  protected:
    explicit ShapeMaker(const std::string& class_name) ;
    virtual Shape *make_shape(std::istream &is) const = 0;

  private:
    typedef ShapeMaker *MakerPtr;
    typedef std::map<std::string, MakerPtr> MakerMap;
    static MakerMap registry; // Static init in cpp file
};

#endif //CPP_PLUGGABLE_FACTORY_SHAPEMAKER_H
