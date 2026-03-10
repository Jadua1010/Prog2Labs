//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_CUSTOMER_H
#define LAB1_CUSTOMER_H

#include "address.h"

class Customer
{
// Use protected because we want these values to be accessible in derrived classes but NOT anywhere else
protected:
	Address address;
public:
	Customer(Address address);

	virtual void printCustomerInfo();
};


#endif //LAB1_CUSTOMER_H