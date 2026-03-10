//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_BUSINESSCUSTOMER_H
#define LAB1_BUSINESSCUSTOMER_H

#include <string>
#include "Customer.h"

class BusinessCustomer : public Customer
{
    private:
        std::string companyName;
        std::string contactName;
        std::string contactEmail;
    public:
        BusinessCustomer(Address _address
            , std::string _companyName
            , std::string _contactName
            , std::string _contactEmail) :
            Customer(_address)
            , companyName(_companyName)
            , contactName(_contactName)
            , contactEmail(_contactEmail)
        {
        }
        void printCustomerInfo() override;
};

#endif //LAB1_BUSINESSCUSTOMER_H