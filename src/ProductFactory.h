#ifndef PRODUCTFACTORY_H_
#define PRODUCTFACTORY_H_

#include <map>
#include <string>

template <typename TB>
struct ProductFactory
{
public:
	typedef std::map<std::string, TB*(*)()> map_type;
	static map_type* productMap;

	ProductFactory()
	{
		getMap();
	}

	static TB* createInstance(std::string const& s)
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

ProductFactory<TB>::map_type* productMap;

#endif /* PRODUCTFACTORY_H_ */
