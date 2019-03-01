/*
 * judge.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Judge.h"
using namespace std;

Judge::Judge()
{
	condition=def;
}

void Judge::getEvaluation(string human, string npc, Player& humanPlayer, Player& NPCPlayer)
{
	condition = def;
	if (human=="Paper")
	{
		if (npc=="Paper")
			condition=tie;
		else if (npc=="Scissors")
			condition=lose;
		else if (npc=="Rock")
			condition=win;
	}
	if (human=="Rock")
	{
		if (npc=="Paper")
			condition=lose;
		else if (npc=="Scissors")
			condition=win;
		else if (npc=="Rock")
			condition=tie;
	}
	if (human=="Scissors")
	{
		if (npc=="Paper")
			condition=win;
		else if (npc=="Scissors")
			condition=tie;
		else if (npc=="Rock")
			condition=lose;
	}

	if (condition==win)
	{
		humanPlayer.incrementScore();
		cout<<"You win!"<<endl;
	}
	else if (condition==lose)
	{
		NPCPlayer.incrementScore();
		cout<<"You lose!"<<endl;
	}
	else if (condition==tie)
	{
		cout<<"You tie!"<<endl;
	}
}


