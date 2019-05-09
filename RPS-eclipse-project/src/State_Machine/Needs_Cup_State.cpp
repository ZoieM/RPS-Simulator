/*
 * NeedsCupState.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Needs_Cup_State.h"

Needs_Cup_State::Needs_Cup_State(Order_State_Machine *osm) {
	// TODO Auto-generated constructor stub
	order_sm = osm;
}

Needs_Cup_State::~Needs_Cup_State() {
	// TODO Auto-generated destructor stub
}

void Needs_Cup_State::take_order()
{
	cout << "ERROR: You already have an order! Here's what it said:\n"
		 << order_sm->ideal_drink.drink_to_string()
		 << endl;
}
//void Needs_Cup_State::get_new_cup()
//{
//
//}
//
//void Needs_Cup_State::brew_tea(Type_of_Tea* tea)
//{
//
//}
//
//void Needs_Cup_State::add_topping(Type_of_Topping* topping)
//{
//
//}
//
//void Needs_Cup_State::give_to_customer()
//{
//
//}

