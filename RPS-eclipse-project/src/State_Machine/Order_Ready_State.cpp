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

}
