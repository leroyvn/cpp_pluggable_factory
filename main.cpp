//=======================================================================
// File:   factory-pattern1.cpp
// Brief:  Factory design pattern with self registering of derived classes.
// Author: Caio Rodrigues
// URL: https://rextester.com/ILKI85678
//=======================================================================

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "Factory.h"

int main() {

    Factory::showClasses();
    std::cout << "\n";
    std::unique_ptr<Base> objBase = Factory::makeUnique("Base");
    if (!objBase)
        std::cout << " ==> Error: object not found in factory" << '\n';
    else
        std::cout << " type of objBase = " << objBase->getType() << "\n";

    std::unique_ptr<Base> objDA = Factory::makeUnique("DerivedA");
    std::cout << " type of derivedA = " << objDA->getType() << "\n";

    std::unique_ptr<Base> objDB = Factory::makeUnique("DerivedB");
    std::cout << " type of derivedB = " << objDB->getType() << "\n";

    std::unique_ptr<Base> objDC = Factory::makeUnique("Derived-error");
    if (!objDC)
        std::cout << " ==> Error: object not found in factory" << '\n';

    return 0;
}
