#ifndef CPP_FACTORY_FACTORY_H
#define CPP_FACTORY_FACTORY_H

#include <map>
#include "Base.h"

// Macro for class registration
#define REGISTER_FACTORY(derivedClass) \
    namespace { auto registry_ ## derivedClass = ConcreteFactory<derivedClass>(#derivedClass); }

// ============  Factory Infrastructure =========== //

class Factory {
  private:
    using FactoryMap = std::map<std::string, Factory *>;
    // Force global variable to be initialized, thus it avoid
    // the initialisation order fiasco.
    static auto getRegister() -> FactoryMap & {
        static FactoryMap classRegister{};
        return classRegister;
    }
  public:
    /** Register factory object of derived class */
    static
    auto registerFactory(const std::string &name, Factory *factory) -> void {
        auto &reg = Factory::getRegister();
        reg[name] = factory;
    }
    /** Show all registered classes */
    static
    auto showClasses() -> void {
        std::cout << " Registered classes. " << "\n";
        std::cout << " =================== " << "\n";
        for (const auto &pair: Factory::getRegister())
            std::cout << " + " << pair.first << "\n";
    }
    /**  Construct derived class returning a raw pointer */
    static
    auto makeRaw(const std::string &name) -> Base * {
        auto it = Factory::getRegister().find(name);
        if (it!=Factory::getRegister().end())
            return it->second->construct();
        return nullptr;
    }

    /** Construct derived class returning an unique ptr  */
    static
    auto makeUnique(const std::string &name) -> std::unique_ptr<Base> {
        return std::unique_ptr<Base>(Factory::makeRaw(name));
    }

    // Destructor
    virtual
    ~Factory() = default;

    virtual
    auto construct() const -> Base * = 0;
};

template<typename DerivedClass>
class ConcreteFactory : Factory {
  public:
    // Register this global object on the Factory register
    ConcreteFactory(const std::string &name) {
        std::cerr << " [TRACE] " << " Registered Class = " << name << "\n";
        Factory::registerFactory(name, this);
    }
    auto construct() const -> Base * {
        return new DerivedClass;
    }
};

#endif //CPP_FACTORY_FACTORY_H
