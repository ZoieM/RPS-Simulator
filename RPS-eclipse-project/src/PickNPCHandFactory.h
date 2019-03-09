/*
 * PickNPCHandFactory.h
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#ifndef PICKNPCHANDFACTORY_H_
#define PICKNPCHANDFACTORY_H_

#include "PickNPCHand.h"
#include "RandomPicker.h"
#include "SimpleMLPicker.h"

class PickNPCHandFactory {
public:
	PickNPCHandFactory();
	virtual ~PickNPCHandFactory();
	static PickNPCHand* make_picker(char which);
};

#endif /* PICKNPCHANDFACTORY_H_ */
