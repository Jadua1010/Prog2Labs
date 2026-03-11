//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_PACKAGE_H
#define LAB1_PACKAGE_H

#include <string>
#include "customer.h"
#include "BusinessCustomer.h"
#include <vector>

class Package
{
// Use protected because we want these values to be accessible in derrived classes but NOT anywhere else
protected:
    Customer* sender;
    Customer* receiver;

    double weight;

public:
    Package(Customer* sender, Customer* receiver, double weight);

    // Make virtual, we want polymorphism
    double calculateCost() const;
    virtual double additionalCost() const;
    std::string getInfo() const {return sender->getName() + " -> " + receiver->getName(); };

    std::tuple<std::vector<BusinessCustomer*>, std::vector<BusinessCustomer*>> printChristmasCardContactPersons(std::vector<BusinessCustomer*> possibleCustomers) {

        // init new lists to keep track of the customers
        std::vector<BusinessCustomer*> processCustomers;
        std::vector<BusinessCustomer*> dontProcessCustomers;

        // Loop though the customers and if they match, put them in the list for matching items, otherwise add them to the remainder list
        for (BusinessCustomer* item : possibleCustomers) {

            if (item == sender || item == receiver) {
                processCustomers.push_back(item);
            }
            else
                dontProcessCustomers.push_back(item);
        }
        // make a tuple to send the ordered customers back to main
        return std::make_tuple(processCustomers, dontProcessCustomers);
    }
};


#endif //LAB1_PACKAGE_H