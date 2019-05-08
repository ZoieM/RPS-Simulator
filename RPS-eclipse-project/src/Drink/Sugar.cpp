/*
 * Sugar.cpp
 * author(s): kristietom
 * description: 
 */

#include "Sugar.h"
#include "Condiment_Decorator.h"

using namespace std;


Sugar::Sugar()
{
	description+="Sugar ";
}


string Sugar::drink_to_string() {
    return description;
}

