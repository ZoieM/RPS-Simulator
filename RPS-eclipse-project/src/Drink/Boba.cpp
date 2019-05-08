/*
 * Boba.cpp
 * author(s): kristietom
 * description: 
 */

#include "Boba.h"
#include "Condiment_Decorator.h"
#include <string>

using namespace std;

Boba::Boba()
{
	description+="Boba ";
}

string Boba::drink_to_string() {
    return description;
}

