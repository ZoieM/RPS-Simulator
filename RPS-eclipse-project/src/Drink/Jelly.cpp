/*
 * Jelly.cpp
 * author(s): kristietom
 * description: 
 */

#include "Jelly.h"
#include "Condiment_Decorator.h"

using namespace std;


Jelly::Jelly()
{
	description+="Jelly ";
}

string Jelly::drink_to_string() {
    return description;
}

