/*
 * FactoryProductBase.h
 *
 *  Created on: Jan 3, 2014
 *      Author: maxwell
 */

#ifndef FACTORYPRODUCTBASE_H_
#define FACTORYPRODUCTBASE_H_

class FactoryProductBase {
public:
	FactoryProductBase();
	virtual ~FactoryProductBase();
	virtual bool produce();
};

#endif /* FACTORYPRODUCTBASE_H_ */
