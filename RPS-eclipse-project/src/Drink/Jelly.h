/*
 * Jelly.h
 * author(s): kristietom
 * description: 
 */

#ifndef JELLY_H
#define JELLY_H

#include "Condiment_Decorator.h"
#include "Drink.h"
#include <string>

using namespace std;

class Jelly : public Condiment_Decorator {
    public:
	Jelly();
    Jelly(Drink the_drink);
    virtual string drink_to_string();
};

#endif
