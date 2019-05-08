/*
 * Sugar.cpp
 * author(s): kristietom
 * description: 
 */

#include "Sugar.h"
#include "Condiment_Decorator.h"

using namespace std;


Sugar::Sugar(Drink* drink)
: Condiment_Decorator(drink) {};


string Sugar::drink_to_string() {
    return pDrink->drink_to_string() + " & sugar";
}

