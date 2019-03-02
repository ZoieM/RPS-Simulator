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
		void requestHand(char c); //member var bool useML will be added later, so this function doesn't have to be random
};



#endif /* NPC_H_ */
