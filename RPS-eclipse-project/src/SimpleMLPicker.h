/*
 * SimpleMLPicker.h
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#ifndef SIMPLEMLPICKER_H_
#define SIMPLEMLPICKER_H_

#include "PickNPCHand.h"

class SimpleMLPicker : public PickNPCHand {
public:
	SimpleMLPicker();
	virtual ~SimpleMLPicker();
	char pick(char c);
};

#endif /* SIMPLEMLPICKER_H_ */
