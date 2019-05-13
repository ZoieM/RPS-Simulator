/*
 * Sugar.cpp
 * author(s): kristietom
 * description: 
 */

#include "Sugar.h"
#include "Condiment_Decorator.h"

using namespace std;


Sugar::Sugar()
{
	description+="Sugar ";
	toppings[0]=Sugar_t;
	number_of_toppings++;
}


string Sugar::drink_to_string() {
    return description;
}

