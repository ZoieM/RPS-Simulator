/*
 * Oolong_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef Oolong_Tea_H
#define Oolong_Tea_H

#include "Drink.h"
#include <string>

using namespace std;

class Oolong_Tea: public Drink {
    public:
    Oolong_Tea();
    virtual string drink_to_string();
};

#endif
