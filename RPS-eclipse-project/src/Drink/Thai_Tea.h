/*
 * Thai_Tea.h
 * author(s): kristietom
 * description: 
 */

#ifndef Thai_Tea_H
#define Thai_Tea_H

#include "Drink.h"
#include <string>

using namespace std;

class Thai_Tea: public Drink {
    public:
    Thai_Tea();
    virtual string drink_to_string();
};

#endif
