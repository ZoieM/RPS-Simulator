/*
 * pickNPCHandFactory.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#include "PickNPCHandFactory.h"


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
