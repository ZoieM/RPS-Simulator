/*
 * Needs_Cup_State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_NEEDS_CUP_STATE_H_
#define STATE_MACHINE_NEEDS_CUP_STATE_H_

#include "State.h"
#include "Order_State_Machine.h"

class Needs_Cup_State : public State {
public:
	Needs_Cup_State(Order_State_Machine *osm);
	virtual ~Needs_Cup_State();
	Order_State_Machine *order_sm;
//	void take_order();
//	void get_new_cup();
//	void brew_tea(Type_of_Tea tea);
//	void add_topping(Type_of_Topping topping);
//	void give_to_customer();
};

#endif /* STATE_MACHINE_NEEDS_CUP_STATE_H_ */
