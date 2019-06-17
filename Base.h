#ifndef CPP_FACTORY_BASE_H
#define CPP_FACTORY_BASE_H

#include <string>
#include <iostream>

class Base {
  public:
    Base() = default;
    // Destructor of base class must always be virtual
    virtual ~Base() = default;
    virtual auto getType() const -> std::string {
        return "Base";
    }
    void showType() {
        std::cout << "Class type = " << this->getType() << "\n";
    }
};

#endif //CPP_FACTORY_BASE_H
