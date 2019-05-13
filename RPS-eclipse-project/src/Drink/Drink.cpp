/*
 * Drink.cpp
 * author(s): kristietom
 * description: 
 */

#include "Drink.h"

Drink::Drink() {
    description = "";
}

string Drink::drink_to_string() {
    return description;
}

int Drink::get_number_of_toppings() {
    return number_of_toppings;
}

bool Drink::same_drinks(Drink other_drink) {
    if (other_drink.tea!=this->tea) return false;
    //else if (other_drink.number_of_toppings!=this->number_of_toppings) return false;
    else if (other_drink.toppings[0]!=this->toppings[0]) return false;
    else return true;
}

bool Drink::has_tea(Type_Of_Tea tea_check)
{
	if (tea_check==tea) return true;
	else return false;
}

bool Drink::has_topping(Type_Of_Topping *topping_check, int number_of_toppings_check){
	if (number_of_toppings_check!=number_of_toppings) return false;
	for (int i=0; i<number_of_toppings; i++)
	{
		if (topping_check[i]!=toppings[i])
		{
			return false;
		}
	}
	return true;
}
