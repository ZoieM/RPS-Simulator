/*
 * Milk.cpp
 * author(s): kristietom
 * description: 
 */

#include "Milk.h"
#include "Condiment_Decorator.h"

using namespace std;


Milk::Milk(Drink* drink)
: Condiment_Decorator(drink) {};

string Milk::drink_to_string() {
    return pDrink->drink_to_string() + " & milk";
}

