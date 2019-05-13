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
	description+="Boba ";
	toppings[0]=Boba_t;
	number_of_toppings++;
}

string Boba::drink_to_string() {
    return description;
}

