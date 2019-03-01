#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
	protected:
		enum hand {rock, paper, scissors, start};
		int score;
		string displayHand;
		hand playerHand;
		~Player();
	public:
		Player();
		int getScore();
		string getHandString();
		virtual void requestHand(){};
		virtual void incrementScore(int condition){};
};

#endif
