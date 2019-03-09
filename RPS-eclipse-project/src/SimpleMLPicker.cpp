/*
 * SimpleMLPicker.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: zoie
 */

#include "SimpleMLPicker.h"

SimpleMLPicker::SimpleMLPicker() {
	// TODO Auto-generated constructor stub

}

SimpleMLPicker::~SimpleMLPicker() {
	// TODO Auto-generated destructor stub
}

//TODO: ****REPLACE THIS CODE WITH ML CODE****
char SimpleMLPicker::pick(char c)
{
	//Choose a random char for the hand
	int npcChoice = 2; //this doesnt work because this is temp code

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
