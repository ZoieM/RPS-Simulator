/*
 * Jelly.cpp
 * author(s): kristietom
 * description: 
 */

#include "Jelly.h"
#include "Condiment_Decorator.h"

Jelly::Jelly(Drink* drink)
: Condiment_Decorator(drink) {};

std::string Jelly::drink_to_string() {
    return pDrink->drink_to_string() + " & jelly";
}

