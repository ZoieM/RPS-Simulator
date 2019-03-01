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
	runGame = false; //game will not be running until it is initialized & user starts a game
	round = 0; //set to 1 when player starts a game
	//define pointers
	humanPlayer = new Human;
	NPCPlayer = new Npc;
	theJudge = new Judge;
}

Game::~Game() {
	//delete any dynamically created variables
	if(humanPlayer!=null)
	{
		delete humanPlayer;
	}
	if(NPCPlayer!=null)
	{
		delete NPCPlayer;
	}
	if(theJudge!=null)
	{
		delete theJudge;
	}
}

void Game::startGame()
{
	runGame = true; //remember that the game is running
	round = 1; //begin with round 1;
	//Explain rules and options to player
	cout << "\n\nINSTRUCTIONS______________________________________________________________________________" << endl
		 << "The game is " << totalRounds << " rounds. Every round, chose one option:\n"
		 << "[r]\tTo play Rock\n"
		 << "[p]\tTo play Paper\n"
		 << "[s]\tTo play Scissors\n"
		 << "\nAs you choose, the computer player will also pick an option. Then, we will see who wins.\n"
		 << "\nEvery round, the winner gets a point. The rules to win are as follows:\n"
		 << "+ Rock beats Scissors\n"
		 << "+ Scissors beats Paper\n"
		 << "+ Paper beats Rock\n"
		 << "But, if you both pick the same option, it's a tie and no one wins any points\n"
		 << "\n\nNOTE: You can quit the game at any time by entering [q] instead of [r], [p], or [s]. Good luck!\n"
		 << endl;

	return;
}

void Game::quitGame()
{
	runGame = false; //Remember we don't want to run the game anymore
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
	char choice = '?'; //initialize choice as an invalid character
	bool validInput = false; //input is invalid until proven otherwise
	hand playerHand = invalid; //player hand is invalid until we collect it
	//Prompt player for a character (r, p, s, or q)
	do{
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
	}while(!validInput);//repeat message if input is invalid
	if(playerHand != invalid)//if the player didn't quit
	{
		humanPlayer->requestHand(choice);
		NPCPlayer->requestHand(choice);//we have to pass a char parameter, but it gets ignored and picks a random value

	}
	//return the character in case game init needs to react (like if player wants to quit).
	return choice;
}

void Game::displayGameResults()
{
	//For the round, display player and computer choices, the evaluation (win, lose, or tie), and the new scores
	cout << "You chose " << humanPlayer->getHandString() << ", and the computer chose " << NPCPlayer->getHandString() << "." << endl;
	theJudge->getEvaluation(humanPlayer->getHandString(), NPCPlayer->getHandString(), *humanPlayer, *NPCPlayer);
	cout<<"Your score: "<<humanPlayer->getScore()<<endl;
	cout<<"NPC score: "<<NPCPlayer->getScore()<<endl;
	return;
}

bool Game::Initialization() {
	//NOTE: Code for playAgain functionality is commented out, b/c we don't have a way to reset scores yet
	char choice; //hold player input
	bool validInput = false; //track if player input is valid
//	bool playAgain = false;
//	do{
	cout << "!!!WELCOME TO RPS SIMULATOR!!!" << endl;//greet player
	//Main Menu (will be more useful for future iterations of the game)
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

	//Code for each round
	while(runGame && round <= totalRounds)//While the player doesn't quit and hasn't completed all the rounds
	{
		//Print out the round number
		cout << "\nROUND " << round << "__________________________________________________________________________________" << endl;
		//Prompt the player to choose their hand
		choice = requestPlayerHand();
		//read the choice to check for any special requests, like quit, help, restart..
		switch (tolower(choice)) { //make case insensitive
		case 'q':	cout << "Quitting the game..." << endl;
					quitGame();
					break;

		default: 	displayGameResults();
					break;
		}
		round++;
	}

	//We stopped doing rounds. Why?
	if(!runGame && round <= totalRounds)//if player quit the game before it ended
	{
		return true; //end the game immediately
	}
	else if(runGame && round > totalRounds)//if player finished every round without quitting
	{
		//Post final score and clean up
		cout << "\nFINAL SCORES______________________________________________________________________________" << endl;
		//Collect the scores
		int finalHumanScore = humanPlayer->getScore();
		int finalNPCScore = NPCPlayer->getScore();
		//Print the final scores
		cout<<"\nYour score: "<< finalHumanScore <<endl;
		cout<<"NPC score: "<< finalNPCScore <<endl;
		//Determine who won the game
		//Possible TODO Make a Judge function that does this instead
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

	return false; //if we stopped the rounds for any other reason, an error occurred.

}
