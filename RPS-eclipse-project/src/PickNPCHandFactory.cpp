/*
 * pickNPCHandFactory.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#include "PickNPCHandFactory.h"

PickNPCHandFactory::PickNPCHandFactory() {
	// TODO Auto-generated constructor stub

}

PickNPCHandFactory::~PickNPCHandFactory() {
	// TODO Auto-generated destructor stub
}

PickNPCHand *PickNPCHandFactory::make_picker(char which)
{
	if (which == 'm')
    {
    	return new SimpleMLPicker();
    }
	else //if  (which == 'r')
    {
    	return new RandomPicker();
    }
}
