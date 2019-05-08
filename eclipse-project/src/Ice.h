/*
 * Ice.h
 * author(s): kristietom
 * description: 
 */

#ifndef ICE_H
#define ICE_H

#include "Condiment_Decorator.h"
#include "Drink.h"

class Ice : public Condiment_Decorator {
    public:
    Ice(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
