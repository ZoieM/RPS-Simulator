/*
 * Condiment_Decorator.h
 * author(s): kristietom
 * description: 
 */

#ifndef CONDIMENT_DECORATOR_H
#define CONDIMENT_DECORATOR_H

#include "Drink.h"
#include <iostream>

class Condiment_Decorator : public Drink {
    public:
    Drink* pDrink;
    Condiment_Decorator(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
