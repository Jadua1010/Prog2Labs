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
#include "address.h"
#include <iostream>

class BusinessCustomer : public Customer
{
    private:
        std::string companyName;
        std::string contactName;
        std::string contactEmail;
    public:
        // Initialize functionality
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

        // override for additional information
        void printCustomerInfo() override {
            std::cout << this->address.toString() << "\t" << this->companyName << "\t" << this->contactName << "\t" << this->contactEmail << std::endl;
        }

        // Override with the contact person name
        std::string getName() const override  {
            return contactName;
        }
};

#endif //LAB1_BUSINESSCUSTOMER_H