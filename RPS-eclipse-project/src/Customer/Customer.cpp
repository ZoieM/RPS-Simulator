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
	int a = rand()%4;
	if (a==0)
	{
		current_order = new Green_Tea;
	}
	else if (a==1)
	{
		current_order = new Black_Tea;
	}
	else if (a==2)
	{
		current_order = new Oolong_Tea;
	}
	else if (a==3)
	{
		current_order = new Thai_Tea;
	}

	if (difficulty==easy)
	{
		return *current_order;
	}
	else
	{
		int i = rand()%5;
		string temp="";
		switch (i)
		{
		case 0: temp = current_order->description;
				current_order = new Boba;
				temp += "with ";
				temp = temp + current_order->description;
				current_order->description.clear();
				current_order->description = temp;
				if (a==0) current_order->tea=Green;
				else if (a==1) current_order->tea=Black;
				else if (a==2) current_order->tea=Oolong;
				else current_order->tea = Thai;
				break;
		case 1: temp = current_order->description;
				current_order = new Ice;
				temp += "with ";
				temp = temp + current_order->description;
				current_order->description.clear();
				current_order->description = temp;
				if (a==0) current_order->tea=Green;
				else if (a==1) current_order->tea=Black;
				else if (a==2) current_order->tea=Oolong;
				else current_order->tea = Thai;
				break;
		case 2: temp = current_order->description;
				current_order = new Jelly;
				temp += "with ";
				temp = temp + current_order->description;
				current_order->description.clear();
				current_order->description = temp;
				if (a==0) current_order->tea=Green;
				else if (a==1) current_order->tea=Black;
				else if (a==2) current_order->tea=Oolong;
				else current_order->tea = Thai;
				break;
		case 3: temp = current_order->description;
				current_order = new Milk;
				temp += "with ";
				temp = temp + current_order->description;
				current_order->description.clear();
				current_order->description = temp;
				if (a==0) current_order->tea=Green;
				else if (a==1) current_order->tea=Black;
				else if (a==2) current_order->tea=Oolong;
				else current_order->tea = Thai;
				break;
		case 4: temp = current_order->description;
				current_order = new Sugar;
				temp += "with ";
				temp = temp + current_order->description;
				current_order->description.clear();
				current_order->description = temp;
				if (a==0) current_order->tea=Green;
				else if (a==1) current_order->tea=Black;
				else if (a==2) current_order->tea=Oolong;
				else current_order->tea = Thai;
				break;
		}
		return *current_order;
	}
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

bool Customer::has_toppings()
{
	if (current_order->number_of_toppings!=0) return true;
	else return false;
}



