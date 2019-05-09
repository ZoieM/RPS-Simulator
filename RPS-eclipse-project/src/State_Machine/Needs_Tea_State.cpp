/*
 * NeedsTeaState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Needs_Tea_State.h"

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

