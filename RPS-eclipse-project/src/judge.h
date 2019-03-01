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
using namespace std;

class Judge
{
	enum evaluation {win, lose, tie, def};
	private:
		evaluation condition;
	public:
		Judge();
		void getEvaluation(string human, string npc);
		int changeScore ();  //return 1 for human to ++, return 2 for npc to ++, return 3 for tie
};



#endif /* JUDGE_H_ */
