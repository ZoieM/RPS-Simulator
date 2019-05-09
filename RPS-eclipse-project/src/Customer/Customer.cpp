/*
 * Customer.cpp
 *
 *  Created on: May 7, 2019
 *      Author: chinjiec
 */

#include "Customer.h"
#include <cstdlib>

void Customer::Init()
{
	current_order->description="";
	difficulty=easy;
}

Drink Customer::get_order()
{
	int i = rand()%4;
	if (i==0)
	{
		current_order = new Green_Tea;
	}
	else if (i==1)
	{
		current_order = new Black_Tea;
	}
	else if (i==2)
	{
		current_order = new Oolong_Tea;
	}
	else if (i==3)
	{
		current_order = new Thai_Tea;
	}
	return *current_order;
}

void Customer::set_difficulty(Difficulty easy_or_hard)
{
	if (easy_or_hard==easy) difficulty=easy;
	else difficulty=hard;
}

Difficulty Customer::return_difficulty()
{
	return difficulty;
}



