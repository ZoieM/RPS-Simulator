#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Npc.h"
#include "Game.h"
#include "Judge.h"
using namespace std;

int main()
{
	Game newGame;
	if(newGame.Initialization())
	{
		return 0;
	}
	return -1;

}
