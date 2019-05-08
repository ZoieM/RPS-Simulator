/*
 * Drink.cpp
 * author(s): kristietom
 * description: 
 */

#include "Drink.h"

Drink::Drink() {
    description = "Drink choice: ";
}

std::string Drink::drink_to_string() {
    return description;
}

int Drink::get_number_of_toppings() {
    return 1;
}

bool Drink::same_drinks(Drink other_drink) {
    return true;
}
