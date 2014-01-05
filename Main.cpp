#include <iostream>
#include "src/FactoryProductBase.h"
#include "src/ProductFactory.h"
#include "src/FactoryRegister.h"

class TestProduct1: public FactoryProductBase
{
public:
	TestProduct1(){};
	~TestProduct1(){};
	bool produce()
	{
		std::cout << "P1" << std::endl;
		return true;
	}
private:
	static FactoryRegister<TestProduct1> reg;
};
FactoryRegister<TestProduct1> TestProduct1::reg("TestProduct1");

class TestProduct2: public FactoryProductBase
{
public:
	TestProduct2(){};
	~TestProduct2(){};
	bool produce()
	{
		std::cout << "P2" << std::endl;
		return true;
	}
private:
	static FactoryRegister<TestProduct2> reg;
};
FactoryRegister<TestProduct2> TestProduct2::reg("TestProduct2");


int main (int argc, char* argv[])
{

	FactoryProductBase* product = ProductFactory::createInstance("TestProduct2");
	product->produce();
	return 0;
}




