/*
 * Boba.h
 * author(s): kristietom
 * description: 
 */

#ifndef BOBA_H
#define BOBA_H

#include "Condiment_Decorator.h"
#include "Drink.h"
#include <string>

using namespace std;

class Boba : public Condiment_Decorator {
    public:
    Boba();
    virtual string drink_to_string();
};

#endif
