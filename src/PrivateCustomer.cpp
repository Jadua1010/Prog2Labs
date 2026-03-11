//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#include "PrivateCustomer.h"
#include "address.h"
#include "Customer.h"
#include <string>

// Initialize fuction
PrivateCustomer::PrivateCustomer(Address _address, std::string _name) :
    Customer(_address)
    , name(_name)
{}