/*
 * OrderStateMachine.cpp
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#include "Order_State_Machine.h"
#include "No_Order_State.h"
#include "Needs_Cup_State.h"
#include "Needs_Tea_State.h"
#include "Needs_Toppings_State.h"
#include "Order_Ready_State.h"

Order_State_Machine::Order_State_Machine(){
	//see init()
}

Order_State_Machine::~Order_State_Machine() {
	// TODO Auto-generated destructor stub

	//delete dynamically created objects
	delete No_Order_State;
	delete Needs_Cup_State;
	delete Needs_Tea_State;
	delete Needs_Toppings_State;
	delete Order_Ready_State;
}

void Order_State_Machine::init(){
	No_Order_State = new ::No_Order_State(this);
	Needs_Cup_State = new ::Needs_Cup_State(this);
	Needs_Tea_State = new ::Needs_Tea_State(this);
	Needs_Toppings_State = new ::Needs_Toppings_State(this);
	Order_Ready_State = new ::Order_Ready_State(this);

	current_state = No_Order_State;

	customer.set_difficulty(easy);

	//drink objects will be defined in other states
}

void Order_State_Machine::change_difficulty(Difficulty difficulty)
{
	this->customer.set_difficulty(difficulty);
}

