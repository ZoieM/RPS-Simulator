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
	//TODO explain rules/options to player
	cout << "\n\nINSTRUCTIONS______________________________________________________________________________" << endl
		 << "The game is " << totalRounds << " rounds. Every round, choose one option:\n"
		 << "[r]\tTo play Rock\n"
		 << "[p]\tTo play Paper\n"
		 << "[s]\tTo play Scissors\n"
		 << "\nAs you choose, the computer player will also pick an option. Then, we will see who wins.\n"
		 << "\nEvery round, the winner gets a point. The rules to win are as follows:\n"
		 << "+ Rock beats Scissors\n"
		 << "+ Scissors beats Paper\n"
		 << "+ Paper beats Rock\n"
		 << "But, if you both pick the same option, it's a tie and no one wins any points\n"
		 << "\nNOTE: Optionally, you can change the NPC mode between random and machine learning by\n using the '-r' and '-m' flags when you enter your hand. The default mode is random.\n"
		 << "\nNOTE: You can quit the game at any time by entering [q] instead of [r], [p], or [s]. Good luck!\n"
		 << endl;

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
	string input; //for collecting user input
	char choice = '?';
	bool validInput = false;
	hand playerHand = invalid;
	//TODO prompt player for a character (r, p, s, or q)
	do{
		cout << "Enter choice: " << flush;
		getline(cin, input); //put the entire line into input string

		//Check user's hand
		choice = input[0]; //user's hand is the first character
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
					 cout << "Invalid Hand. Please enter another choice." << endl;
					 break;
		}

		if(input.size()>1) //if input is longer than one character, check for valid flags
		{
			input.erase(0, 2); //remove first char and space
			cout << "Input is "<< input << " . You entered a flag" << endl;

			//Check for other flags in player input, if present
			if(input[0] == '-')
			{
				switch(tolower(input[1]))//make sure the flag character is case insensitive
				{
					case 'r': validInput = true;
							   cout << "Setting NPC mode to Random..." << endl;
							   NPCPlayer->changePicker('r');
							   break;
					case 'm': validInput = true;
							   cout << "Setting NPC mode to Machine Learning..." << endl;
							   NPCPlayer->changePicker('m');
							   break;
					default:   validInput = false;
							   cout << "Invalid Flag. Please enter another choice." << endl;
							   break;
				}
			}
			else
			{
				validInput = false;
				cout << "Invalid Input. Please enter another choice." << endl;
			}
		}
	}while(!validInput);//repeat message if input is invalid

	//Once validated, set the player's hand
	if(playerHand != invalid)
	{
		humanPlayer->requestHand(choice);
		NPCPlayer->requestHand(choice);//we have to pass a char parameter, but it gets ignored and picks a random value

	}

	return choice;
}

void Game::displayGameResults()
{
	cout << "You chose " << humanPlayer->getHandString() << ", and the computer chose " << NPCPlayer->getHandString() << "." << endl;
	switch(theJudge->getEvaluation(humanPlayer->getHandString(), NPCPlayer->getHandString()))
	{
	case 1: humanPlayer->incrementScore();//first hand won
			cout << "You win :)" << endl;
			break;
	case 2: NPCPlayer->incrementScore(); //first hand lost
			cout << "You lose :(" << endl;
			break;
	case 3: cout << "You tied!" << endl;
			break;//tie
	default:cout << "WARNING: JUDGE EVALUATION ERROR" << endl;
			break;
	}
	cout<<"Your score: "<<humanPlayer->getScore()<<endl;
	cout<<"NPC score: "<<NPCPlayer->getScore()<<endl;
	//TODO print result of the round
	return;
}

bool Game::Initialization() {
	char choice;
	bool validInput = false;
//	bool playAgain = false;


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
			cout << "\nROUND " << round << "__________________________________________________________________________________" << endl;

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
			cout << "\nFINAL SCORES______________________________________________________________________________" << endl;
			int finalHumanScore = humanPlayer->getScore();
			int finalNPCScore = NPCPlayer->getScore();
			cout<<"\nYour score: "<< finalHumanScore <<endl;
			cout<<"NPC score: "<< finalNPCScore <<endl;

			if(finalHumanScore > finalNPCScore )
			{
				cout << "YOU WON THE GAME :) CONGRATULATIONS!" << endl;
			}
			else if(finalHumanScore < finalNPCScore )
			{
				cout << "YOU LOST THE GAME :( BETTER LUCK NEXT TIME!" << endl;
			}
			else if(finalHumanScore == finalNPCScore )
			{
				cout << "YOU TIED! WOW, WHAT ARE THE ODDS?" << endl;
			}
			return true;
		}
//		else
//		{
//			//if this else statement is reached, an error occurred. End the program.
//			return false;
//		}

//		do{
//			cout << "Would you like to play again? [y/n]: " << flush;
//			cin >> choice;
//			switch (tolower(choice)) {//make case insensitive
//				case 'y':  validInput = true;
//						   playAgain = true;
//						   break;
//
//				case 'n':  return true;
//
//				default: validInput = false;
//						 cout << "Invalid Input. Please enter another choice." << endl;
//						 break;
//			}
//		}while(!validInput);//repeat message if input is invalid

//	}while(playAgain);

	return false;

}
