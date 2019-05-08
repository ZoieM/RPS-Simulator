/*
 * Milk.h
 * author(s): kristietom
 * description: 
 */

#ifndef MILK_H
#define MILK_H

#include "Condiment_Decorator.h"
#include "Drink.h"
#include <string>

using namespace std;

class Milk : public Condiment_Decorator {
    public:
    Milk();
    virtual string drink_to_string();
};

#endif
