/*
 * Condiment_Decorator.h
 * author(s): kristietom
 * description: 
 */

#ifndef CONDIMENT_DECORATOR_H
#define CONDIMENT_DECORATOR_H

#include "Drink.h"
#include <iostream>
#include <string>

using namespace std;

class Condiment_Decorator : public Drink {
    public:
	Condiment_Decorator();
    string drink_to_string();
};

#endif
