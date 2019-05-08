/*
 * Milk.h
 * author(s): kristietom
 * description: 
 */

#ifndef MILK_H
#define MILK_H

#include "Condiment_Decorator.h"
#include "Drink.h"

class Milk : public Condiment_Decorator {
    public:
    Milk(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
