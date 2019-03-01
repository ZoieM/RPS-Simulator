/*
 * judge.h
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#ifndef JUDGE_H_
#define JUDGE_H_

#include <iostream>
#include <string>
#include "Player.h"
#include "Npc.h"
#include "Human.h"

using namespace std;

class Judge
{
	enum evaluation {win, lose, tie, def};
	private:
		evaluation condition;
	public:
		Judge();
		void getEvaluation(string human, string npc, Player& humanPlayer, Player& NPCPlayer);
};



#endif /* JUDGE_H_ */
