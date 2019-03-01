#include<iostream>
#include"Game.h"

using namespace std;

int main()
{
	Game newGame();
	if(newGame.Initialization())
	{
		return 0;
	}
	return -1;

}
