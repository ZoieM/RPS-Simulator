/*
 * Thai_Tea.cpp
 * author(s): kristietom
 * description: 
 */

#include "Thai_Tea.h"

Thai_Tea::Thai_Tea() {
    description = description + "Thai Tea ";
}

std::string Thai_Tea::drink_to_string() {
    return description;
}
