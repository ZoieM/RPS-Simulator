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
#include "../Drink/Green_Tea.h"
#include "../Drink/Black_Tea.h"
#include "../Drink/Oolong_Tea.h"
#include "../Drink/Thai_Tea.h"
#include "../Drink/Boba.h"
#include "../Drink/Jelly.h"
#include "../Drink/Ice.h"
#include "../Drink/Milk.h"
#include "../Drink/Sugar.h"
using namespace std;

class Drink; //forward declaration

enum Difficulty
{
	easy,
	hard
};

class Customer
{
private:
	Drink *current_order; //should be Drink instead of string
	Difficulty difficulty;
public:
	void Init();
	virtual Drink get_order();  //should be Drink instead of string
	void set_difficulty(Difficulty easy_or_hard);
	bool has_toppings();
	Difficulty return_difficulty ();
};



#endif /* ECLIPSE_PROJECT_SRC_CUSTOMER_H_ */
