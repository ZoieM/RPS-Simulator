/*
 * Drink.cpp
 * author(s): kristietom
 * description: 
 */

#include "Drink.h"

Drink::Drink() {
    description = "";
    for(int i = 0; i < MAX_TOPPINGS; i++)
    {
    	toppings[i] = Undefined_t;
    }
}

string Drink::drink_to_string() {
    return description;
}

int Drink::get_number_of_toppings() {
    return number_of_toppings;
}

bool Drink::same_drinks(Drink other_drink) {
//    if(other_drink.get_number_of_toppings() != this->number_of_toppings) return false;
//	if(this->has_bad_ingredient(other_drink)) return false;
//    else return true;
	if(other_drink.description != description)
	{
		return false;
	}
	return true;
}

bool Drink::has_bad_ingredient(Drink ideal_drink)
{
	//if teas are different, return true
	if (ideal_drink.tea!=this->tea)
	{
		return true;
	}

	//if this drink has an ingredient that the ideal drink doesn't have, return true
	for(int i = 0; i < number_of_toppings; i++)
	{
		if(!(ideal_drink.has_topping(this->toppings[i])))
		{
			return true;
		}
	}

	//otherwise, return false
	return false;
}

bool Drink::has_tea(Type_Of_Tea tea_check)
{
	if (tea_check==tea) return true;
	else return false;
}

bool Drink::has_topping(Type_Of_Topping topping_check){

	if (number_of_toppings < 1)
	{
		return false;
	}

	//for all toppings
	for(int i = 0; i < number_of_toppings; i++)
	{
		//see if the passed topping matches
		if (toppings[i] == topping_check)
		{
			return true;
		}
	}

	return false;
}

bool Drink::can_add_more_toppings()
{
	if(number_of_toppings < MAX_TOPPINGS)
	{
		return true;
	}
	//else
	return false;
}
