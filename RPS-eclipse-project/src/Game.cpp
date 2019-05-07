/*
 * Game.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Game.h"

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::init_game()
{
	do {
		query_difficulty();
		run_game();
		display_score();
	} while(query_play_again());

	return;
}

void Game::query_difficulty()
{
	//TODO: Query user for difficulty, and update Order_SM.customer
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
