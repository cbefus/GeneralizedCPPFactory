#include <iostream>
#include "src/ProductFactory.h"
#include "src/FactoryRegister.h"

/*******************************************************************/
/* The Base Class with virtual Interface for your factory products */
class AnimalBase {
public:
	AnimalBase(){};
	virtual ~AnimalBase(){};
	virtual bool speak(){
		std::cout << "Speak not overloaded for animal." << std::endl;
		return true;
	}
};

/*******************************************************************/
/* An example product class that self registers */
class Duck: public AnimalBase
{
public:
	Duck(){};
	~Duck(){};
	bool speak()
	{
		std::cout << "Quack" << std::endl;
		return true;
	}
private:
	static FactoryRegister<Duck, AnimalBase> reg;
};
FactoryRegister<Duck, AnimalBase> Duck::reg("Duck");

/*******************************************************************/
/* Another example product class that self registers. */
class Dog: public AnimalBase
{
public:
	Dog(){};
	~Dog(){};
	bool speak()
	{
		std::cout << "Bark" << std::endl;
		return true;
	}
private:
	static FactoryRegister<Dog, AnimalBase> reg;
};
FactoryRegister<Dog, AnimalBase> Dog::reg("Dog");

/*******************************************************************/
/* How to produce and use products from a factory using the registered string */
int main (int argc, char* argv[])
{
	AnimalBase* animal = ProductFactory<AnimalBase>::createInstance("Duck");
	animal->speak();
	return 0;
}




