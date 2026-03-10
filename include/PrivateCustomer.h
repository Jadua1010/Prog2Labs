//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_PRIVATECUSTOMER_H
#define LAB1_PRIVATECUSTOMER_H

#include <string>
#include "Customer.h"

class PrivateCustomer : public Customer
{
    private:
        std::string name;
    public:
        PrivateCustomer(Address _address, std::string _name);

        void printCustomerInfo() override;
};

#endif //LAB1_PRIVATECUSTOMER_H