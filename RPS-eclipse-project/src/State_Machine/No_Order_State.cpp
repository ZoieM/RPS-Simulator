/*
 * NoOrderState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "No_Order_State.h"

No_Order_State::No_Order_State(Order_State_Machine *osm) {
	// TODO Auto-generated constructor stub
	order_sm = osm;
}

No_Order_State::~No_Order_State() {
	// TODO Auto-generated destructor stub
}

void No_Order_State::take_order()
{
	//Take the customer's order
	order_sm->ideal_drink = order_sm->customer.get_order();
	//Tell the user what the customer ordered
	cout << "Here is what the customer asked for:\n"
		 << order_sm->ideal_drink.drink_to_string()
		 << endl;

	//For demo, only brew tea, then order up
	order_sm->current_state = order_sm->Needs_Tea_State;
}

void No_Order_State::brew_tea(std::string tea)
{
	std::cout << "ERROR: You can't make any tea until you take a customer's order." << std::endl;
//	if(order_sm->customer.return_difficulty() == hard)
//	{
//		order_sm->mistakes++;
//	}
}

void No_Order_State::give_to_customer()
{
	std::cout << "ERROR: You don't have any tea to give to the customer. Take the customer's order." << std::endl;
	//	if(order_sm->customer.return_difficulty() == hard)
	//	{
	//		order_sm->mistakes++;
	//	}
}

