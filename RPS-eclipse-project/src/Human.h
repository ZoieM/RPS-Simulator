/*
 * Human.h
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Human: public Player
{
	protected:
		~Human();
	public:
		void requestHand(char c);
		void incrementScore(int condition);
};



#endif /* HUMAN_H_ */
