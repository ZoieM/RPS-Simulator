/*
 * judge.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "judge.h"
using namespace std;

Judge::Judge()
{
	condition=def;
}

int Judge::changeScore()
{
	if (condition==win)
		return 1;
	else if (condition==lose)
		return 2;
	else if (condition==tie)
		return 3;

	return 4; //for errors
}

void Judge::getEvaluation(string human, string npc)
{
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
}


