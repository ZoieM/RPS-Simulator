/*
 * main.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include <iostream>
#include "Game.h"
#include "Drink.h"
#include "Black_Tea.h"
#include "Green_Tea.h"
#include "Oolong_Tea.h"
#include "Thai_Tea.h"
#include "Boba.h"
#include "Ice.h"
#include "Jelly.h"
#include "Milk.h"
#include "Sugar.h"

int main()
{
	Game Boba_Mania;
	Boba_Mania.init_game();

	Drink drink;
	std::cout << drink.drink_to_string() << std::endl;

	/*
	Black_Tea btea;
	std::cout << btea.drink_to_string() << std::endl;

	Green_Tea gtea;
	std::cout << gtea.drink_to_string() << std::endl;

	Oolong_Tea otea;
	std::cout << otea.drink_to_string() << std::endl;

	Thai_Tea ttea;
	std::cout << ttea.drink_to_string() << std::endl;

	Boba ttea_boba= (Boba(&ttea));
	std::cout << ttea_boba.drink_to_string() << std::endl;

	Boba ttea_double_boba = Boba(&ttea_boba);
	std::cout << ttea_double_boba.drink_to_string() << std::endl;

	Sugar ttea_double_boba_sugar = Sugar(&ttea_double_boba);
	std::cout << ttea_double_boba_sugar.drink_to_string() << std::endl;
	*/

	return 0;
}

