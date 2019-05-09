/*
 * OrderReadyState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Order_Ready_State.h"

Order_Ready_State::Order_Ready_State(Order_State_Machine *osm) {
	// TODO Auto-generated constructor stub
	order_sm = osm;
}

Order_Ready_State::~Order_Ready_State() {
	// TODO Auto-generated destructor stub
}

void Order_Ready_State::take_order()
{
	cout << "ERROR: You need to give the customer their drink before you can take another order."
		 << endl;
}

void Order_Ready_State::brew_tea(std::string tea)
{
	std::string input;
	bool input_is_valid = false;

	do{
		std::cout << "You have already made " << order_sm->current_drink->drink_to_string()
			 << ".\nDo you want to throw this away? ([Y]es / [N]o): "
			 << flush;

		std::getline(std::cin, input);

		switch(tolower(input[0]))
		{
			case 'y': 	input_is_valid = true;
						std::cout << "Brewing a new cup of tea..." << std::endl;
						order_sm->current_state = order_sm->Needs_Tea_State;//change state
						order_sm->Needs_Tea_State->brew_tea(tea);//brew tea
						break;
			case 'n':	input_is_valid = true;
						std::cout << "You decided not to brew any tea." << std::endl;
						break;
			default:	std::cout << "Invalid Input! Enter [y] or [n]." << std::endl;
		}
	}while(!input_is_valid);
}

void Order_Ready_State::give_to_customer()
{
	//If made the tea the customer ordered
	if(order_sm->current_drink->same_drinks(order_sm->ideal_drink))
	{
		cout << "Thanks! This is exactly what I ordered!" << endl;
		order_sm->order_done = true;
		delete order_sm->current_drink;
		order_sm->current_state = order_sm->No_Order_State;
	}
	else//we made the wrong tea
	{
		order_sm->mistakes++;
		cout << "This isn't what I ordered! Please, make it again." << endl;
	}
}