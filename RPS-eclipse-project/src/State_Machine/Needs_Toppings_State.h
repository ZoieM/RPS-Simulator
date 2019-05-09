/*
 * Needs_Toppings_State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_NEEDS_TOPPINGS_STATE_H_
#define STATE_MACHINE_NEEDS_TOPPINGS_STATE_H_

#include "State.h"
#include "Order_State_Machine.h"

class Needs_Toppings_State : public State{
public:
	Needs_Toppings_State(Order_State_Machine *osm);
	virtual ~Needs_Toppings_State();
	Order_State_Machine *order_sm;
	void take_order();
};

#endif /* STATE_MACHINE_NEEDS_TOPPINGS_STATE_H_ */
