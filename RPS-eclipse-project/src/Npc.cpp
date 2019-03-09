/*
 * Npc.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Npc.h"
#include <cstdlib>
using namespace std;

Npc::Npc()
{
	currentPicker = 'r'; //r for random, m for simple ML
	picker = PickNPCHandFactory::make_picker(currentPicker); //random by default
}

//TODO: Update this class to use our abstract class, pickNPCHand
void Npc::requestHand(char c)
{
	//Choose a random char for the hand
	char npcChoice = picker->pick(c);

	//Update the playerHand, which represents the NPC's choice
	if (npcChoice=='r')
	{
		playerHand=rock;
	}
	else if (npcChoice=='p')
	{
		playerHand=paper;
	}
	else if (npcChoice=='s')
	{
		playerHand=scissors;
	}

	//Update the displayHand string, which also represents our choice
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

bool Npc::changePicker(char c) //choose r for random, m for simple ML
{
	if(tolower(c) != currentPicker)
	{
		switch(c)
		{
		case 'r': 	currentPicker = 'r';
					//delete current picker and dynamically create a new random picker
					delete picker;
					picker = PickNPCHandFactory::make_picker(currentPicker); //random by default
					break;
		case 'm': 	currentPicker = 'm';
					//delete current picker and dynamically create a new simpleML picker
					delete picker;
					picker = PickNPCHandFactory::make_picker(currentPicker); //random by default
					break;
		default:	return false; //invalid choice. this should never be reached.
					break;
		}
		return true;
	}
	else//do nothing if equal
	{
		return false;
	}
}

