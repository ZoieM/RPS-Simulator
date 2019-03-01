/*
 * Game.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: zoie
 */

#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

Game::Game() {
	// TODO Auto-generated constructor stub
	runGame = false; //game will not be running until it is initialized & user starts a game
	round = 0; //set to 1 when player starts a game
	humanPlayer = new Human;
	NPCPlayer = new Npc;
	theJudge = new Judge;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::startGame()
{
	runGame = true;
	round = 1; //begin with round 1;
	//TODO to create human, npc, and judge--SHOULD THESE BE PRIVATE VARS? OR DYNAMIC?
	//TODO explain rules/options to player
	return;
}

void Game::quitGame()
{
	runGame = false;
	//add more?
	return;
}

bool Game::getRunGame() {
	if(runGame){
		return true;
	}
	else
	{
		return false;
	}
}

char Game::requestPlayerHand()//TODO change this to get enum
{
	char choice = '?';
	bool validInput = false;
	hand playerHand = invalid;
	//TODO prompt player for a character (r, p, s, or q)
	cout << "Enter choice: " << flush;
	cin >> choice;
	switch (tolower(choice)) {//make case insensitive
					case 's':  validInput = true;
							   playerHand = scissors;
							   break;

					case 'r':  validInput = true;
							   playerHand = rock;
							   break;

					case 'p':  validInput = true;
							   playerHand = paper;
							   break;

					case 'q':  validInput = true;
							   break;

					default: validInput = false;
							 cout << "Invalid Input. Please enter another choice." << endl;
							 break;
					}
	if(playerHand != invalid)
	{
		humanPlayer.requestHand(choice);
	}
	//TODO evaluate character with a switch statement.
		//If valid char (r, p, or s) create enumerated type and finish round
		//If invalid, return the character so other request is dealt with.
	cout << "[Playing a round]" << endl;
	return choice;
}

void displayGameResults()
{
	cout << "__GAME RESULTS__" << endl;
	//TODO print result of the round
	return;
}

bool Game::Initialization() {
	char choice;
	bool validInput = false;
	bool playAgain = false;

	do{
		cout << "Welcome to RPS Simulator." << endl;
		do{
			cout << "Enter [s] to start a new game or [q] to quit the program: " << flush;
			cin >> choice;
			switch (tolower(choice)) {//make case insensitive
				case 's':  validInput = true;
						   startGame(); //set runGame true
						   break;

				case 'q':  validInput = true;
						   quitGame(); //set runGame false
						   break;

				default: validInput = false;
						 cout << "Invalid Input. Please enter another choice." << endl;
						 break;
				}
		}while(!validInput);//repeat message if input is invalid

		while(runGame && round <= totalRounds)
		{
			choice = requestPlayerHand();
			//check for any special requests, like quitting, helping, restarting..
			switch (tolower(choice)) { //make case insensitive
			case 'q':	cout << "Quitting the game..." << endl;
						quitGame();
						break;

			default: 	displayGameResults();
						break;
			}
			round++;
		}
		if(!runGame && round <= totalRounds)//if player quit the game before it ended
		{
			return true;
		}
		else if(runGame && round > totalRounds)//if player finished every round without quitting
		{
			//TODO post final score and clean up
			return true;
		}
		else
		{
			//if this else statement is reached, an error occurred. End the program.
			return false;
		}

		do{
			cout << "Would you like to play again? [y/n]: " << flush;
			cin >> choice;
			switch (tolower(choice)) {//make case insensitive
				case 'y':  validInput = true;
						   playAgain = true;
						   break;

				case 'n':  validInput = true;
						   playAgain = false;
						   break;

				default: validInput = false;
						 cout << "Invalid Input. Please enter another choice." << endl;
						 break;
			}
		}while(!validInput);//repeat message if input is invalid

	}while(playAgain);

	return true;

}
