#ifndef CPP_PLUGGABLE_FACTORY_SHAPE_H
#define CPP_PLUGGABLE_FACTORY_SHAPE_H

class Shape {
  public:
    Shape() = default;
    virtual ~Shape() = default;
    virtual void do_something() = 0;
};

#endif //CPP_PLUGGABLE_FACTORY_SHAPE_H
