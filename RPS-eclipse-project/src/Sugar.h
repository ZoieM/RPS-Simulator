/*
 * Sugar.h
 * author(s): kristietom
 * description: 
 */

#ifndef SUGAR_H
#define SUGAR_H

#include "Condiment_Decorator.h"
#include "Drink.h"

class Sugar : public Condiment_Decorator {
    public:
    Sugar(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
