/*
 * Customer.h
 *
 *  Created on: May 7, 2019
 *      Author: chinjiec
 */

#ifndef ECLIPSE_PROJECT_SRC_CUSTOMER_H_
#define ECLIPSE_PROJECT_SRC_CUSTOMER_H_

#include <string>
#include <iostream>
#include "../Drink/Drink.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

enum Difficulty
{
	easy,
	hard
};

class Customer
{
private:
	Difficulty difficulty;
public:
<<<<<<< HEAD
	Customer(); //constructor
=======
	Drink current_order; //should be Drink instead of string
	void Init();
>>>>>>> a4715bba1e897dc8aa45bafd7ee4950a46359cb9
	virtual Drink get_order();  //should be Drink instead of string
	void set_difficulty(Difficulty easy_or_hard);
};



#endif /* ECLIPSE_PROJECT_SRC_CUSTOMER_H_ */
