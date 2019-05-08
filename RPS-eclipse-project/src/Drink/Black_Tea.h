/*
 * Black_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef Black_Tea_H
#define Black_Tea_H

#include "Drink.h"
#include <string>

using namespace std;

class Black_Tea: public Drink {
    public:
    Black_Tea();
    virtual string drink_to_string();
};

#endif
