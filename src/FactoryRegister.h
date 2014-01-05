#ifndef FACTORYREGISTER_H_
#define FACTORYREGISTER_H_

#include <string>
#include <utility>
#include "ProductFactory.h"
#include "FactoryProductBase.h"

template<typename T> FactoryProductBase * createT() { return new T; }

template<typename T>
struct FactoryRegister : ProductFactory
{
    FactoryRegister(std::string const& s)
    {
        getMap()->insert(std::make_pair<std::string, FactoryProductBase*(*)()>(s, &createT<T>));
    }
};

#endif  /* FACTORYREGISTER_H_ */


