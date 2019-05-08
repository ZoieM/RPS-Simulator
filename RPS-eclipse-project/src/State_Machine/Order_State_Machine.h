/*
 * Order_State_Machine.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef ORDER_STATE_MACHINE_H_
#define ORDER_STATE_MACHINE_H_

class Order_State_Machine {
public:
	//Constructor and Destructor
	Order_State_Machine(Difficulty difficulty);
	virtual ~Order_State_Machine();

	//Possible States for State Machine
	State No_Order_State;
	State Empty_Cup_State;
	State Needs_Tea_State;
	State Needs_Toppings_State;
	State Order_Ready_State;

	//Current State of State Machine
	State current_state = No_Order_State;

	//Member Variables
	Customer customer;	 //The customer produces drink orders. Simple or Complex depending on difficulty.
 	Drink ideal_drink; 	 //The drink the customer ordered. Defined after No_Order_State.
	Drink current_drink; //The drink the user has made or is still making.
	int mistakes = 0;
};

#endif /* ORDER_STATE_MACHINE_H_ */
