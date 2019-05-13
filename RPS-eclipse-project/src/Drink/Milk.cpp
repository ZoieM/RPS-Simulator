/*
 * Milk.cpp
 * author(s): kristietom
 * description: 
 */

#include "Milk.h"
#include "Condiment_Decorator.h"

using namespace std;


Milk::Milk()
{
	description+="Milk ";
	toppings[0]=Milk_t;
	number_of_toppings++;
}

string Milk::drink_to_string() {
    return description;
}

