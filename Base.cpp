#include "Base.h"
#include "Factory.h"

// Register Base class
namespace {
// Anonymous namespace is used to make the definitions here private to the current
// compilation unit (current file). It is equivalent to the old C static keyword.
// It could be placed at Base.cpp
//ConcreteFactory<Base> registry_Base("Base");

//  Registration with macro.
REGISTER_FACTORY(Base)
}
