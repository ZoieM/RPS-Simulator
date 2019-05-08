/*
 * Drink.h
 * author(s): kristietom
 * description: 
 */

#ifndef DRINK_H
#define DRINK_H

#include <iostream>

class Drink {
    public:
    Drink();
    std::string description;
    int number_of_toppings;
    static const int MAX_TOPPINGS = 5;

    virtual std::string drink_to_string();
    int get_number_of_toppings();
    bool same_drinks(Drink other_drink);
    // bool has_tea(Type_Of_Tea tea);
    // bool has_topping(Type_Of_Topping topping);
};


#endif