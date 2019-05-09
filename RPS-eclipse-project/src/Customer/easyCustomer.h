/*
 * easyCustomer.h
 *
 *  Created on: May 7, 2019
 *      Author: chinjiec
 */

#ifndef ECLIPSE_PROJECT_SRC_EASYCUSTOMER_H_
#define ECLIPSE_PROJECT_SRC_EASYCUSTOMER_H_

#include "Customer.h"

class easyCustomer: public Customer
{
public:
	Drink get_order(){return current_order;};
};



#endif /* ECLIPSE_PROJECT_SRC_EASYCUSTOMER_H_ */
