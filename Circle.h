//
// Created by Vincent Leroy on 2019-06-16.
//

#ifndef CPP_PLUGGABLE_FACTORY_CIRCLE_H
#define CPP_PLUGGABLE_FACTORY_CIRCLE_H

#include "Shape.h"

struct Circle : public Shape {
  Circle() = default;
  ~Circle() = default;
  void do_something() override;
};

#endif //CPP_PLUGGABLE_FACTORY_CIRCLE_H
