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
