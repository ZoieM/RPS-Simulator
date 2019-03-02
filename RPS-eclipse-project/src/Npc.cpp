/*
 * Npc.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Npc.h"
#include <cstdlib>
using namespace std;

void Npc::incrementScore(int condition)
{
	if (condition==2)
		score++;
}

void Npc::requestHand(char c)
{
	int npcChoice = (rand()%3)+1;
	if (npcChoice==1)
		playerHand=rock;
	else if (npcChoice==2)
		playerHand=paper;
	else if (npcChoice==3)
		playerHand=scissors;
}


