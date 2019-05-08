/*
 * Customer.cpp
 *
 *  Created on: May 7, 2019
 *      Author: chinjiec
 */

#include "Customer.h"

void Customer::Init()
{
	current_order.description="";
	difficulty=easy;
}

Drink Customer::get_order()
{
	return current_order;
}

void Customer::set_difficulty(Difficulty easy_or_hard)
{
	if (easy_or_hard==easy) difficulty=easy;
	else difficulty=hard;
}



