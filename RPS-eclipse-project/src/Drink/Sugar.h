/*
 * Sugar.h
 * author(s): kristietom
 * description: 
 */

#ifndef SUGAR_H
#define SUGAR_H

#include "Condiment_Decorator.h"
#include "Drink.h"
#include <string>

using namespace std;

class Sugar : public Condiment_Decorator {
    public:
    Sugar();
    virtual string drink_to_string();
};

#endif
