/*
 * Game.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Game.h"
#include <iostream>
#include <string>

Game::Game() {
	// TODO Auto-generated constructor stub
	this->total_orders = ORDERS_PER_GAME;
	this->current_order = 1; //begin at order #1
	this->score = 0; //score begins at 0%
	this->Order_SM.init();
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init_game()
{
	do {
		display_title();
		query_difficulty();
		run_game();
		display_score();
	} while(query_play_again());

	return;
}

void Game::display_title()
{
	//Display "BOBA MANIA"
	std::cout << " ____  _____  ____    __      __  __    __    _  _  ____    __   " << std::endl
	 	 << "(  _ \\(  _  )(  _ \\  /__\\    (  \\/  )  /__\\  ( \\( )(_  _)  /__\\  " << std::endl
	 	 << " ) _ < )(_)(  ) _ < /(__)\\    )    (  /(__)\\  )  (  _)(_  /(__)\\ " << std::endl
		 << "(____/(_____)(____/(__)(__)  (_/\\/\\_)(__)(__)(_)\\_)(____)(__)(__)" << std::endl;

	//Display Boba Tea ASCII Art
	std::cout 	<< "\t\t     __\n"
			 	<< "\t\t    / /\n" <<
					"\t\t   / /\n" <<
					"\t\t  / /\n" <<
					"\t====================\n" <<
					"\t|                  |\n" <<
					"\t|                  |\n" <<
					"\t |                |\n" <<
					"\t |                |\n" <<
					"\t |                |\n" <<
					"\t |             _  |\n" <<
					"\t |  _    _    (_) |\n" <<
					"\t | (_)  (_)_   _  |\n" <<
					"\t |   _   _(_) (_) |\n" <<
					"\t |  (_) (_) _  _  |\n" <<
					"\t |_____(_)_(_)(_)_|\n" << std::endl;

	return;
}

void Game::query_difficulty()
{
	//TODO: Query user for difficulty, and update Order_SM.customer
	std::string input;
	bool input_is_valid = false;
	do{
		std::cout << "Select Difficulty ([E]asy or [H]ard): " << std::flush;
		std::cin  >> input;

		switch(tolower(input[0]))
		{
			case 'e': 	input_is_valid = true;
						this->Order_SM.change_difficulty(easy);
						std::cout << "Beginning an Easy Game..." << std::endl;
						break;
			case 'h':	input_is_valid = true;
						this->Order_SM.change_difficulty(hard);
						std::cout << "Beginning a Hard Game..." << std::endl;
						break;
			default:	std::cout << "Invalid Input! Enter [e] or [h]." << std::endl;
		}
	}while(!input_is_valid);

	return;
}

void Game::run_game()
{
	//TODO: For each order in total_orders, go through all states of Order_SM.
	return;
}

void Game::display_score()
{
	//TODO: Print "GAME OVER" and the user's final score
	return;
}

bool Game::query_play_again()
{
	//TODO: Query user if they would like to play again and return the corresponding value.
	return false;
}
