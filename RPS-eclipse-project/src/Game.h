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
#include "Player.h"
#include "Judge.h"
#include "Npc.h"
#include "Human.h"

using namespace std;
enum hand { rock, paper, scissors, invalid };

class Game {
public:
	Game();
	virtual ~Game();
	bool Initialization();
	bool getRunGame();
	const int totalRounds = 20;
private:
	Player *humanPlayer;
	Player *NPCPlayer;
	Judge *theJudge;
	bool runGame;
	int round; //Game will last totalRounds
	void startGame();
	void quitGame();
	char requestPlayerHand();
	void displayGameResults();
};

#endif /* GAME_H_ */
