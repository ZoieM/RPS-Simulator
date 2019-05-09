/*
 * No_Order_State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_NO_ORDER_STATE_H_
#define STATE_MACHINE_NO_ORDER_STATE_H_

#include "State.h"
#include "Order_State_Machine.h"

class No_Order_State : public State{
public:
	No_Order_State(Order_State_Machine *osm);
	virtual ~No_Order_State();
	Order_State_Machine *order_sm;
	void take_order();
	void brew_tea(std::string tea);
	void give_to_customer();
};

#endif /* STATE_MACHINE_NO_ORDER_STATE_H_ */
