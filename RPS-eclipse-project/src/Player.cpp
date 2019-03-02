#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
	score=0;
	displayHand=="Start";
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
	switch (playerHand)
	{
		case 0:
			displayHand="Rock"; break;
		case 1:
			displayHand="Paper"; break;
		case 2:
			displayHand="Scissors"; break;
		case 3:
			displayHand="Start"; break;
	}
	return displayHand;
}


