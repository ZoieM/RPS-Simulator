/*
 * State.h
 *
 *  Created on: May 7, 2019
 *      Author: zoie
 */

#ifndef STATE_MACHINE_STATE_H_
#define STATE_MACHINE_STATE_H_

#include "../Drink/Drink.h"

class State
{
	public:
		State(){};
		virtual ~State(){};
		virtual void take_order() = 0;
//		virtual void get_new_cup() = 0;
//		virtual void brew_tea(Drink tea) = 0;
//		virtual void add_topping(Drink topping) = 0;
//		virtual void give_to_customer() = 0;
};

#endif /* STATE_MACHINE_STATE_H_ */
