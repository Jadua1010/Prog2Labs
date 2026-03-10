//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#include "BusinessCustomer.h"
#include "address.h"
#include "Customer.h"



void BusinessCustomer::printCustomerInfo() override {
    std::cout << this->address << "\t" << this->companyName << "\t" << this->contactName << "\t" << this->contactEmail << std::endl;

}