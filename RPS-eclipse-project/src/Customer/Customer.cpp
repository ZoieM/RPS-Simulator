/*
 * Customer.cpp
 *
 *  Created on: May 7, 2019
 *      Author: chinjiec
 */

#include "Customer.h"
#include "../Drink/Drink.h"
#include <cstdlib>

void Customer::Init()
{
	current_order.description="";
	difficulty=easy;
}

Drink Customer::get_order()
{
	int i = rand()%4;
	if (i==0)
	{
		current_order.description = "Green Tea";
		current_order.tea=Green_Tea;
	}
	else if (i==1)
	{
		current_order.description = "Oolong Tea";
		current_order.tea = Oolong_Tea;
	}
	else if (i==2)
	{
		current_order.description = "Black Tea";
		current_order.tea = Black_Tea;
	}
	else if (i==3)
	{
		current_order.description = "Thai Tea";
		current_order.tea = Thai_Tea;
	}
	return current_order;
}

void Customer::set_difficulty(Difficulty easy_or_hard)
{
	if (easy_or_hard==easy) difficulty=easy;
	else difficulty=hard;
}



