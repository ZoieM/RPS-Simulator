#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
using namespace std;

class Player
{
	private:
		friend class Judge;
	protected:
		enum hand {rock, paper, scissors, start};
		int score;
		string displayHand;
		hand playerHand;
		void incrementScore();
		~Player();
	public:
		Player();
		int getScore();
		string getHandString();
		virtual void requestHand(char c){};

};

#endif /* PLAYER_H_ */
