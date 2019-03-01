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
#include "Player.h"
using namespace std;

class Npc: public Player
{
	protected:
		~Npc();
	public:
		void requestHand(char c);//TODO: Fix this function so it doesn't collect a character if it isn't needed
};



#endif /* NPC_H_ */
