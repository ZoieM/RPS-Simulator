/*
 * Random.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#include "RandomPicker.h"
#include <cstdlib>

RandomPicker::RandomPicker() {
	// TODO Auto-generated constructor stub

}

RandomPicker::~RandomPicker() {
	// TODO Auto-generated destructor stub
}

char RandomPicker::pick(char c)
{
	//Choose a random char for the hand
	int npcChoice = (std::rand()%3)+1;

	if (npcChoice==1)
	{
		return 'r';
	}
	else if (npcChoice==2)
	{
		return 'p';
	}
	else //if (npcChoice==3)
	{
		return 's';
	}
}
