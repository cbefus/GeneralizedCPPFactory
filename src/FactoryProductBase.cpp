/*
 * FactoryProductBase.cpp
 *
 *  Created on: Jan 3, 2014
 *      Author: maxwell
 */

#include <iostream>
#include "FactoryProductBase.h"

FactoryProductBase::FactoryProductBase()
{
}

FactoryProductBase::~FactoryProductBase()
{
}

bool FactoryProductBase::produce()
{
	std::cout << "Base" << std::endl;
	return true;
}

