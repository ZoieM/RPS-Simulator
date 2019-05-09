/*
 * Drink.h
 * author(s): kristietom
 * description: 
 */

#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>


using namespace std;

enum Type_Of_Tea { Green_Tea, Black_Tea, Oolong_Tea, Thai_Tea, Undefined };
enum Type_Of_Topping { Boba, Jelly, Milk, Ice, Sugar };

class Drink {
	public:
	string description;
    static const int MAX_TOPPINGS = 5;
    int number_of_toppings=0;
	Type_Of_Tea tea;
	Type_Of_Topping toppings[MAX_TOPPINGS];
    Drink();
    virtual ~Drink();
    bool same_drinks(Drink other_drink); //judge to determine whether the choices are correct
    bool has_tea(Type_Of_Tea tea_check); //check whether it has the corresponding kind of tea
    bool has_topping(Type_Of_Topping *topping_check, int number_of_toppings_check); //check whether corresponding toppings
    int get_number_of_toppings(); //returns the number of toppings
    virtual string drink_to_string();
};


#endif
