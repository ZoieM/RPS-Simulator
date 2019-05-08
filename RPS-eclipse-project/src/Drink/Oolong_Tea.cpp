/*
 * Oolong_Tea.cpp
 * author(s): kristietom
 * description: 
 */

#include "Oolong_Tea.h"

Oolong_Tea::Oolong_Tea() {
    description = description + "Oolong Tea, ";
}

std::string Oolong_Tea::drink_to_string() {
    return description;
}
