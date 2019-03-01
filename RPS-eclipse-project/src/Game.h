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
using namespace std;

const int totalRounds = 20;
enum hand { rock, paper, scissors, invalid };

class Game {
public:
	Game();
	virtual ~Game();
	bool Initialization();
	bool getRunGame();
private:
	Human humanPlayer();
	NPC NPCPlayer();
	bool runGame;
	int round; //TODO add support so game will play exactly totalRounds
	void startGame();
	void quitGame();
	char requestPlayerHand();
	void displayGameResults();
};

#endif /* GAME_H_ */
