/*
 * Green_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef GREEN_TEA_H
#define GREEN_TEA_H

#include "Drink.h"

class Green_Tea: public Drink {
    public:
    Green_Tea();
    virtual std::string drink_to_string();
};

#endif