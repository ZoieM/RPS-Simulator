/*
 * NeedsTeaState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Needs_Tea_State.h"
//#include "../Drink/Green_Tea.h"
//#include "../Drink/Black_Tea.h"
//#include "../Drink/Thai_Tea.h"
//#include "../Drink/Oolong_Tea.h"

using namespace std;

Needs_Tea_State::Needs_Tea_State(Order_State_Machine *osm) {
	// TODO Auto-generated constructor stub
	order_sm = osm;
}

Needs_Tea_State::~Needs_Tea_State() {
	// TODO Auto-generated destructor stub
}

void Needs_Tea_State::take_order()
{
	cout << "ERROR: You already have an order! Here's what it said:\n"
		 << order_sm->ideal_drink.drink_to_string()
		 << endl;
}
void Needs_Tea_State::brew_tea(std::string tea)
{
	bool valid_tea = false;
	//Make the string lowercase
	for(std::string::size_type i = 0; i < tea.length(); i++ )
	{
		tea[i]=tolower(tea[i]);
	}
	//Look for a valid tea type. If valid, brew it.
	if(tea.find("green") != std::string::npos)
	{
		valid_tea = true;
		if(order_sm->current_drink != NULL) //Delete the tea if one already existed
		{
			//delete order_sm->current_drink;
		}
		order_sm->current_drink = new Green_Tea;
		std::cout << "You brewed a cup of Green Tea." << endl;
	}
	else if(tea.find("oolong") != std::string::npos)
	{
		valid_tea = true;
		if(order_sm->current_drink != NULL) //Delete the tea if one already existed
		{
			//delete order_sm->current_drink;
		}
		order_sm->current_drink = new Oolong_Tea;
		std::cout << "You brewed a cup of Oolong Tea." << endl;
	}
	else if(tea.find("black") != std::string::npos)
	{
		valid_tea = true;
		if(order_sm->current_drink != NULL) //Delete the tea if one already existed
		{
			//delete order_sm->current_drink;
		}
		order_sm->current_drink = new Black_Tea;
		std::cout << "You brewed a cup of Black Tea." << endl;
	}
	else if(tea.find("thai") != std::string::npos)
	{
		valid_tea = true;
		if(order_sm->current_drink != NULL) //Delete the tea if one already existed
		{
			//delete order_sm->current_drink;
		}
		order_sm->current_drink = new Thai_Tea;
		std::cout << "You brewed a cup of Thai Tea." << endl;
	}
	else //invalid tea type
	{
		cout << "You can't brew that type of tea. Here are the types of teas you can brew:\n"
			 << "\tGreen Tea\n"
			 << "\tBlack Tea\n"
			 << "\tOolong Tea\n"
			 << "\tThai Tea\n"
			 << endl;
	}

	//State Transition
	if(valid_tea)//If we brewed tea
	{
		if(order_sm->ideal_drink.get_number_of_toppings() > 0)
		{
			//If the customer ordered one or more toppings
			order_sm->current_state = order_sm->Needs_Toppings_State;
		}
		else
		{
			//If the customer didn't order any toppings
			order_sm->current_state = order_sm->Order_Ready_State;
		}


	}
}

void Needs_Tea_State::add_topping(string topping)
{
	cout << "Error: You haven't made any tea yet! Make some tea before adding the toppings."<< endl;
}

void Needs_Tea_State::give_to_customer()
{
	cout << "Error: You haven't made any tea yet! Make some tea before giving the customer their order." << endl;
}
