#ifndef CPP_FACTORY_DERIVEDA_H
#define CPP_FACTORY_DERIVEDA_H

#include "Base.h"

class DerivedA : public Base {
  public:
    DerivedA() {}
    auto getType() const -> std::string {
        return "DerivedA";
    }
};

#endif //CPP_FACTORY_DERIVEDA_H
