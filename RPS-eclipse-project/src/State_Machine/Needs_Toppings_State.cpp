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
	cout << "Error: You already brewed the tea!"<<endl;
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
		order_sm->current_drink->toppings[0] = Boba_t;
		cout<<"You added boba into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("jelly") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink->toppings[0] = Jelly_t;
		cout<<"You added Jelly into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("milk") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink->toppings[0] = Milk_t;
		cout<<"You added Milk into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("ice") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink->toppings[0] = Ice_t;
		cout<<"You added ice into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else if(topping.find("sugar") != std::string::npos)
	{
		valid_topping = true;
		order_sm->current_drink->toppings[0] = Sugar_t;
		cout<<"You added sugar into the "<<order_sm->current_drink->drink_to_string()<<endl;
	}
	else //invalid tea type
	{
		cout << "You can't add that type of topping. Here are the types of toppings you can brew:\n"
			 << "\tBoba\n"
			 << "\tJelly\n"
			 << "\tMilk\n"
			 << "\tIce\n"
			 << "\tSugar\n"
			 << endl;
	}

	//State Transition
	if(valid_topping)//If we brewed tea
	{
		//For demo, only brew tea, then order up
		order_sm->current_state = order_sm->Order_Ready_State;

	}
}

void Needs_Toppings_State::give_to_customer()
{
	cout << "You can't give customer a Drink you haven't add toppings yet"<<endl;
}
