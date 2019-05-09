/*
 * Order_Ready_State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_ORDER_READY_STATE_H_
#define STATE_MACHINE_ORDER_READY_STATE_H_

#include "State.h"
#include "Order_State_Machine.h"

class Order_Ready_State : public State {
public:
	Order_Ready_State(Order_State_Machine *osm);
	virtual ~Order_Ready_State();
	Order_State_Machine *order_sm;
	void take_order();
	void brew_tea(std::string tea);
};

#endif /* STATE_MACHINE_ORDER_READY_STATE_H_ */
