/*
 * Needs_Tea_State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_NEEDS_TEA_STATE_H_
#define STATE_MACHINE_NEEDS_TEA_STATE_H_

#include "State.h"
#include "Order_State_Machine.h"

class Needs_Tea_State : public State {
public:
	Needs_Tea_State(Order_State_Machine *osm);
	virtual ~Needs_Tea_State();
	Order_State_Machine *order_sm;
};

#endif /* STATE_MACHINE_NEEDS_TEA_STATE_H_ */
