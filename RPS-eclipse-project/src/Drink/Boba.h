/*
 * Boba.h
 * author(s): kristietom
 * description: 
 */

#ifndef BOBA_H
#define BOBA_H

#include "Condiment_Decorator.h"
#include "Drink.h"

class Boba : public Condiment_Decorator {
    public:
    Boba(Drink* drink);
    virtual std::string drink_to_string();
};

#endif
