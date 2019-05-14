/*
 * Ice.h
 * author(s): kristietom
 * description: 
 */

#ifndef ICE_H
#define ICE_H

#include "Condiment_Decorator.h"
#include "Drink.h"
#include <string>

using namespace std;

class Ice : public Condiment_Decorator {
    public:
	Ice();
    Ice(Drink the_drink);
    virtual string drink_to_string();
};

#endif
