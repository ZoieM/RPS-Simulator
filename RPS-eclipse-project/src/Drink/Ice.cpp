/*
 * Ice.cpp
 * author(s): kristietom
 * description: 
 */

#include "Ice.h"
#include "Condiment_Decorator.h"

using namespace std;


Ice::Ice()
{
	description+="Ice ";
}

string Ice::drink_to_string() {
    return description;
}

