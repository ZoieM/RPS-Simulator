/*
 * Ice.cpp
 * author(s): kristietom
 * description: 
 */

#include "Ice.h"
#include "Condiment_Decorator.h"

Ice::Ice(Drink* drink)
: Condiment_Decorator(drink) {};

std::string Ice::drink_to_string() {
    return pDrink->drink_to_string() + " & ice";
}

