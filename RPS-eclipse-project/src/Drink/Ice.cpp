/*
 * Ice.cpp
 * author(s): kristietom
 * description: 
 */

#include "Ice.h"
#include "Condiment_Decorator.h"

using namespace std;


Ice::Ice(Drink* drink)
: Condiment_Decorator(drink) {};

string Ice::drink_to_string() {
    return pDrink->drink_to_string() + " & ice";
}

