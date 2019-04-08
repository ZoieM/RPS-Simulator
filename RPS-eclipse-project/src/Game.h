/*
 * Game.h
 *
 *  Created on: Feb 28, 2019
 *      Author: zoie
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include "Npc.h"
#include "Human.h"
#include "judge.h"
using namespace std;

enum hand { rock, paper, scissors, invalid };

class Game {
public:
	Game();
	virtual ~Game();
	bool Initialization();
	bool getRunGame();
private:
	Player *humanPlayer;
	Player *NPCPlayer;
	Judge *theJudge;
	bool runGame;			//track if game has been started or quit
	int round; 				//track current round
	int totalRounds;
	void startGame();
	void quitGame();
	char requestPlayerHand();
	void displayGameResults();
	bool setTotalRounds(int rounds);
};

#endif /* GAME_H_ */
