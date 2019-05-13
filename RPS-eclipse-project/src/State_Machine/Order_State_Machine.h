/*
 * Order_State_Machine.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_ORDER_STATE_MACHINE_H_
#define STATE_MACHINE_ORDER_STATE_MACHINE_H_

//#include "../Drink/Drink.cpp"
//#include "../Customer/Customer.cpp"
#include "State.h"
#include "../Customer/Customer.h"
class Drink;

class Order_State_Machine{
public:
	//Constructor and Destructor
	Order_State_Machine();
	virtual ~Order_State_Machine();

	void init();

	//Possible States for State Machine
	State* No_Order_State;
	//State* Needs_Cup_State;
	State* Needs_Tea_State;
	State* Order_Ready_State;
	State* Needs_Toppings_State;

	//Current State of State Machine
	State* current_state;

	//Member Variables
	Customer customer;	 //The customer produces drink orders. Simple or Complex depending on difficulty.
 	Drink ideal_drink; 	 //The drink the customer ordered. Defined after No_Order_State.
	Drink* current_drink; //The drink the user has made or is still making.
	int mistakes = 0;
	bool order_done = false;
};

#endif /* STATE_MACHINE_ORDER_STATE_MACHINE_H_ */
