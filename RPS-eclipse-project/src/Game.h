/*
 * Game.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef GAME_H_
#define GAME_H_

const int ORDERS_PER_GAME = 3;

class Game{
	public:
		Game();				//constructor
		virtual ~Game();	//destructor
		void init_game();	//call this function to begin the game
	private:
		//functions used in init_game()
		void display_title();
		void query_difficulty();
		void run_game();
		void display_score();
		bool query_play_again();
		//member variables
		//Order_State_Machine Order_SM; //TODO: Define Order_State_Machine class
		int total_orders = ORDERS_PER_GAME;
		int current_order = 1; //begin at order #1
		double score = 0; //score begins at 0%
};

#endif /* GAME_H_ */
