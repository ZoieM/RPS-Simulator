/*
 * Npc.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Npc.h"
#include <cstdlib>
using namespace std;

void Npc::requestHand(char c)
{
	//char parameter is ignored until ML is implemented
	int npcChoice = (rand()%3)+1;
	if (npcChoice==1)
	{
		playerHand=rock;
	}
	else if (npcChoice==2)
	{
		playerHand=paper;
	}
	else if (npcChoice==3)
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


