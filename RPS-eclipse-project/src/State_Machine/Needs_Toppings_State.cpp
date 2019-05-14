/*
 * NeedsToppingsState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Needs_Toppings_State.h"

Needs_Toppings_State::Needs_Toppings_State(Order_State_Machine *osm) {
	// TODO Auto-generated constructor stub
	order_sm = osm;
}

Needs_Toppings_State::~Needs_Toppings_State() {
	// TODO Auto-generated destructor stub
}

void Needs_Toppings_State::take_order()
{
	cout << "ERROR: You already have an order! Here's what it said:\n"
		 << order_sm->ideal_drink.drink_to_string()
		 << endl;
}

void Needs_Toppings_State::brew_tea(string tea)
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

void Needs_Toppings_State::add_topping(string topping)
{
	bool valid_topping = false;
	//Make the string lowercase
	for(std::string::size_type i = 0; i < topping.length(); i++ )
	{
		topping[i]=tolower(topping[i]);
	}
	//Look for a valid tea type. If valid, brew it.
	if(topping.find("boba") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink = new Boba(*(order_sm->current_drink));
		cout<<"You added boba into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("jelly") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink = new Jelly(*(order_sm->current_drink));
		cout<<"You added Jelly into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("milk") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink = new Milk(*(order_sm->current_drink));
		cout<<"You added Milk into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("ice") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink = new Ice(*(order_sm->current_drink));
		cout<<"You added ice into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("sugar") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink = new Sugar(*(order_sm->current_drink));
		cout<<"You added sugar into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else //invalid tea type
	{
		cout << "You can't add that type of topping. Here are the types of toppings you can add:\n"
			 << "\tBoba\n"
			 << "\tJelly\n"
			 << "\tMilk\n"
			 << "\tIce\n"
			 << "\tSugar\n"
			 << endl;
	}

	//State Transition
	if(valid_topping)//If we added a topping
	{
		if(order_sm->ideal_drink.same_drinks(*(order_sm->current_drink)))
		{
			order_sm->current_state = order_sm->Order_Ready_State;
		}
	}
}

void Needs_Toppings_State::give_to_customer()
{
	order_sm->Order_Ready_State->give_to_customer();
}
