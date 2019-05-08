/*
 * Green_Tea.cpp
 * author(s): kristietom
 * description: 
 */

#include "Green_Tea.h"

using namespace std;


Green_Tea::Green_Tea() {
    description = description + "Green Tea, ";
}

string Green_Tea::drink_to_string() {
    return description;
}
