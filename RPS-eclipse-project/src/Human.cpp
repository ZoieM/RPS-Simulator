/*
 * Human.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: JieFu
 */

#include "Human.h"
using namespace std;

void Human::incrementScore(int condition)
{
	if (condition==1)
		score++;
}

void Human::requestHand()
{
	char choice;
	cout<<"Pick your hand: [r]ock, [p]aper, [s]cissor"<<endl;
	cin>>choice;
	if (choice=='r')
		playerHand=rock;
	else if (choice=='p')
		playerHand=paper;
	else if (choice=='s')
		playerHand=scissors;
}


