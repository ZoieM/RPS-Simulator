/*
 * Human.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Human.h"
using namespace std;

void Human::requestHand(char c)
{
	char choice=c;
	if (choice=='r')
	{
		playerHand=rock;
	}
	else if (choice=='p')
	{
		playerHand=paper;
	}
	else if (choice=='s')
	{
		playerHand=scissors;
	}

	//Update the displayHand string
	switch (playerHand)
	{
		case 0:
			displayHand="Rock"; break;
		case 1:
			displayHand="Paper"; break;
		case 2:
			displayHand="Scissors"; break;
		case 3:
			displayHand="Start"; break;
	}
}

bool Human::changePicker(char c){
	return false;
}


