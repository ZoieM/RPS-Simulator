/*
 * Black_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef Black_Tea_H
#define Black_Tea_H

#include "Drink.h"

class Black_Tea: public Drink {
    public:
    Black_Tea();
    virtual std::string drink_to_string();
};

#endif