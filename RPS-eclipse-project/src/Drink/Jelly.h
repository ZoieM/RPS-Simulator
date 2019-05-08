/*
 * Jelly.h
 * author(s): kristietom
 * description: 
 */

#ifndef JELLY_H
#define JELLY_H

#include "Condiment_Decorator.h"
#include "Drink.h"

class Jelly : public Condiment_Decorator {
    public:
    Jelly(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
