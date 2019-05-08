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
	Drink get_order()
	{
		// this section is for handling toppings
		int random = rand()%2 + 1; //random range from 1 - 2 toppings
		current_order.number_of_toppings=random;
		for (int i=0; i<random; i++)
		{
			random = rand()%4;
			switch (random)
			{
			case 0:
				current_order.toppings[i]=Boba; break;
			case 1:
				current_order.toppings[i]=Jelly; break;
			case 2:
				current_order.toppings[i]=Milk; break;
			case 3:
				current_order.toppings[i]=Ice; break;
			case 4:
				current_order.toppings[i]=Sugar; break;
			}
		}

		//this section is for handling type of tea
		random = rand()%4;
		switch (random)
		{
		case 0:
			current_order.tea=Green_Tea; break;
		case 1:
			current_order.tea=Black_Tea; break;
		case 2:
			current_order.tea=Oolong_Tea; break;
		case 3:
			current_order.tea=Thai_Tea; break;
		}
		return current_order;
	};
};



#endif /* ECLIPSE_PROJECT_SRC_EASYCUSTOMER_H_ */
