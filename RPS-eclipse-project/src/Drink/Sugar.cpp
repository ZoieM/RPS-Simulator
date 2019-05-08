/*
 * Sugar.cpp
 * author(s): kristietom
 * description: 
 */

#include "Sugar.h"
#include "Condiment_Decorator.h"

Sugar::Sugar(Drink* drink)
: Condiment_Decorator(drink) {};

std::string Sugar::drink_to_string() {
    return pDrink->drink_to_string() + " & sugar";
}

