/*
 * Black_Tea.cpp
 * author(s): kristietom
 * description: 
 */

#include "Black_Tea.h"

using namespace std;


Black_Tea::Black_Tea() {
	tea=Black;
    description = description + "Black Tea ";
}

string Black_Tea::drink_to_string() {
    return description;
}
