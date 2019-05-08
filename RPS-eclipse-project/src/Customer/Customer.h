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
#include <stdio.h>
#include <stdlib.h>
#include "Drink.h"
using namespace std;

class Customer
{
	enum Difficulty
	{
		easy,
		hard
	};
private:
	Difficulty difficulty;
public:
	Drink current_order; //should be Drink instead of string
	void Init();
	virtual Drink get_order();  //should be Drink instead of string
	void set_difficulty(Difficulty easy_or_hard);
};



#endif /* ECLIPSE_PROJECT_SRC_CUSTOMER_H_ */
