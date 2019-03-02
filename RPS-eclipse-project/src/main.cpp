//============================================================================
// Name        : RPS-Simulator.cpp
// Author      : Jie Fu Chi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Player.h"
#include "judge.h"
#include "Human.h"
#include "Npc.h"
#include "Game.h"
using namespace std;

/*
int main() {
	cout << "!!!Welcome to RPS Simulator!!!" << endl; // prints !!!Hello World!!!
	Player *human_test=new Human;
	Player *npc_test=new Npc;
	Judge judge_test;
	char choice='r';
	cout << "Game start!"<<endl;
	for (int i =0; i<5; i++)
	{
		human_test->requestHand(choice);
		cout<<"You picked: "<<human_test->getHandString()<<endl;
		npc_test->requestHand(choice);
		cout<<"NPC picked: "<<npc_test->getHandString()<<endl;
		judge_test.getEvaluation(human_test->getHandString(),npc_test->getHandString());
		human_test->incrementScore(judge_test.changeScore());
		npc_test->incrementScore(judge_test.changeScore());
		cout<<"Human score: "<<human_test->getScore()<<endl;
		cout<<"NPC score: "<<npc_test->getScore()<<endl;
	}
	cout<<"Game finished"<<endl;
	return 0;
}
*/

int main()
{
	Game newGame;
	if(newGame.Initialization())
	{
		return 0;
	}
	return -1;

}
