#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
	score=0;
	displayHand=="Invalid";
	playerHand=start;
}

int Player::getScore()
{
	return score;
}

void Player::incrementScore()
{
		score++;
}

string Player::getHandString()
{
	return displayHand;
}

char Player::getHandChar()
{
	return tolower(displayHand[0]);
}


