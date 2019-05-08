/*
 * Condiment_Decorator.cpp
 * author(s): kristietom
 * description: 
 */

#include "Condiment_Decorator.h"
#include "Drink.h"

Condiment_Decorator::Condiment_Decorator(Drink* drink)
: pDrink(drink) {};

std::string Condiment_Decorator::drink_to_string() {
    return pDrink->drink_to_string();
}
