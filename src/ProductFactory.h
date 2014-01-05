#ifndef PRODUCTFACTORY_H_
#define PRODUCTFACTORY_H_

#include <map>
#include <string>
#include "FactoryProductBase.h"

typedef std::map<std::string, FactoryProductBase*(*)()> map_type;

struct ProductFactory
{
public:
	static map_type* productMap;
	static FactoryProductBase* createInstance(std::string const& s)
	{
		map_type::iterator it = getMap()->find(s);
		if (it == getMap()->end())
		{
			return 0;
		}
		return it->second();
	}
protected:
	static map_type* getMap() //intentionally never deleted
	{
		if (!productMap)
		{
			productMap = new map_type;
		}
		return productMap;
	}
};

map_type* ProductFactory::productMap = NULL;

#endif /* PRODUCTFACTORY_H_ */
