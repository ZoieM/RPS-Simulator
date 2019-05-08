/*
 * Boba.cpp
 * author(s): kristietom
 * description: 
 */

#include "Boba.h"
#include "Condiment_Decorator.h"

Boba::Boba(Drink* drink)
: Condiment_Decorator(drink) {};

std::string Boba::drink_to_string() {
    return pDrink->drink_to_string() + " & boba";
}

