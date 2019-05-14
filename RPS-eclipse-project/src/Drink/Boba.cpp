/*
 * Boba.cpp
 * author(s): kristietom
 * description: 
 */

#include "Boba.h"
#include "Condiment_Decorator.h"
#include <string>

using namespace std;

Boba::Boba()
{
	if(!can_add_more_toppings())
	{
		cout << "ERROR! ATTEMPTED TO ADD TOPPING WITHOUT ROOM." << endl;
		abort();
	}
	if(number_of_toppings > 0)
	{
		description+=", ";
	}
	{
		description+="with ";
	}
	description+="Boba";
	toppings[number_of_toppings] == Boba_t;
	number_of_toppings++;
}
Boba::Boba(Drink the_drink)
{
	this->tea = the_drink.tea;
	this->number_of_toppings = the_drink.number_of_toppings;
	for(int i = 0; i < number_of_toppings; i++)
	{
		this->toppings[i] = the_drink.toppings[i];
	}
	this->description = the_drink.description;

	//WARNING! CONSTRUCTOR ASSUMES YOU CHECKED IF THERE WAS STILL ROOM TO ADD A TOPPING!
	if(!can_add_more_toppings())
	{
		cout << "ERROR! ATTEMPTED TO ADD TOPPING WITHOUT ROOM." << endl;
		abort();
	}
	else
	{
		if(number_of_toppings > 0)
		{
			description+=", ";
		}
		else
		{
			description+="with ";
		}
		description+="Boba";
		toppings[number_of_toppings] == Boba_t;
		number_of_toppings++;
	}
}

string Boba::drink_to_string() {
    return description;
}

