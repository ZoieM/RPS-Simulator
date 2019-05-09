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
};



#endif /* ECLIPSE_PROJECT_SRC_CUSTOMER_H_ */
