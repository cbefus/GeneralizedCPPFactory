#ifndef FACTORYREGISTER_H_
#define FACTORYREGISTER_H_

#include <string>
#include <utility>
#include "ProductFactory.h"

template<typename T, typename TB> TB * createT() { return new T; }

template<typename T, typename TB>
struct FactoryRegister : ProductFactory<TB>
{
    FactoryRegister(std::string const& s)
    {
        getMap()->insert(std::make_pair<std::string, TB*(*)()>(s, &createT<T, TB>));
    }
};

#endif  /* FACTORYREGISTER_H_ */


