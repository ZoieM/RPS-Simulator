/*
 * Random.h
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#ifndef RANDOMPICKER_H_
#define RANDOMPICKER_H_

#include "PickNPCHand.h"

class RandomPicker : public PickNPCHand {
public:
	RandomPicker();
	~RandomPicker();
	char pick(char c);
};

#endif /* RANDOMPICKER_H_ */
