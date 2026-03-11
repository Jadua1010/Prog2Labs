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
#include <iostream>
#include <string>

class Customer
{
// Use protected because we want these values to be accessible in derrived classes but NOT anywhere else
protected:
	Address address;
public:
	Customer(Address address);

	// Basic print customer info function, which could be overridden by its children
	virtual void printCustomerInfo() {
		std::cout << this->address.toString() << std::endl;
	}

	// quite useless fucntion for just the customer, but children can fill in their name information
	virtual std::string getName() const {
		return "";
	}
};


#endif //LAB1_CUSTOMER_H