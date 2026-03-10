//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#include "Customer.h"
#include <string>


Customer::Customer(Address _address) :
	address(_address)
{

}

virtual void Customer::printCustomerInfo()  {
	std::cout << this->address;
}