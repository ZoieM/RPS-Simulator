/*
 * Milk.cpp
 * author(s): kristietom
 * description: 
 */

#include "Milk.h"
#include "Condiment_Decorator.h"

Milk::Milk(Drink* drink)
: Condiment_Decorator(drink) {};

std::string Milk::drink_to_string() {
    return pDrink->drink_to_string() + " & milk";
}

