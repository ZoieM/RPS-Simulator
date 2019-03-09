/*
 * Npc.h
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#ifndef NPC_H_
#define NPC_H_

#include <iostream>
#include <string>

#include "PickNPCHandFactory.h"
#include "PickNPCHand.h"
#include "Player.h"
using namespace std;

class Npc: public Player
{
	private:
		PickNPCHand *picker; //random by default
		char currentPicker; //r for random, m for simple ML
	protected:
		~Npc();
	public:
		Npc();
		bool changePicker(char c); //choose r for random, m for simple ML
		void requestHand(char c); //member var bool useML will be added later, so this function doesn't have to be random
};



#endif /* NPC_H_ */
