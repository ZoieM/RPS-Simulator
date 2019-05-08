/*
 * Jelly.cpp
 * author(s): kristietom
 * description: 
 */

#include "Jelly.h"
#include "Condiment_Decorator.h"

using namespace std;


Jelly::Jelly(Drink* drink)
: Condiment_Decorator(drink) {};

string Jelly::drink_to_string() {
    return pDrink->drink_to_string() + " & jelly";
}

