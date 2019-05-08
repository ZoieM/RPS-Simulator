/*
 * Thai_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef Thai_Tea_H
#define Thai_Tea_H

#include "Drink.h"

class Thai_Tea: public Drink {
    public:
    Thai_Tea();
    virtual std::string drink_to_string();
};

#endif