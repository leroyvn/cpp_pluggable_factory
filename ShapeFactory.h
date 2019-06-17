#ifndef CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H
#define CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H

#include <istream>
#include <string>
#include <map>
#include "Shape.h"

class ShapeFactory {
  public:
    virtual ~ShapeFactory() = default;
    static void show_registered();
    static Shape *new_shape(std::istream &is);
    static std::unique_ptr<Shape> new_shape_unique(std::istream &is);

  protected:
    explicit ShapeFactory(const std::string &class_name);
    virtual Shape *make_shape(std::istream &is) const = 0;
    virtual std::unique_ptr<Shape> make_shape_unique(std::istream &is) const = 0;

  private:
    typedef ShapeFactory *FactoryPtr;
    typedef std::map<std::string, FactoryPtr> FactoryMap;
    static FactoryMap registry; // Static init in cpp file
};

#endif //CPP_PLUGGABLE_FACTORY_SHAPEFACTORY_H
