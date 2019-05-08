/*
 * Condiment_Decorator.cpp
 * author(s): kristietom
 * description: 
 */

#include "Condiment_Decorator.h"
#include "Drink.h"

using namespace std;

Condiment_Decorator::Condiment_Decorator()
{

}

string Condiment_Decorator::drink_to_string() {
    return description;
}
