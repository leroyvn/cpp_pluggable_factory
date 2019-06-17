#ifndef CPP_FACTORY_DERIVEDB_H
#define CPP_FACTORY_DERIVEDB_H

#include "Base.h"

class DerivedB : public Base {
  public:
    DerivedB() {}
    auto getType() const -> std::string {
        return "DerivedB";
    }
};

#endif //CPP_FACTORY_DERIVEDB_H
