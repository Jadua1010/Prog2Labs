//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#include <iostream>
#include <vector>
#include "package.h"
#include "twoDayPackage.h"
#include "overnightPackage.h"
#include "Customer.h"
#include "BusinessCustomer.h"
#include "PrivateCustomer.h"


int main(void) {

    // Create some hardcoded customers
    std::vector<Customer*> customers;


    // Add at least 3 customers of each type to the array
    // Format is address, name for private customers

    customers.push_back(
        new PrivateCustomer(
            Address("1 Pie Street", "Enschede", "1000AB", "NL")
            , "John Doe"
        )
    );

    
    customers.push_back(
        new PrivateCustomer(
            Address("3 Sea Street", "Zaanstad", "2000CD", "NL")
            , "Sam Smith"
        )
    );
    customers.push_back(
        new PrivateCustomer(
            Address("8 Oui Street", "Paris", "45685", "FR")
            , "Johan Warm"
        )
    );

    // Format is address, companyName, contactName, ContactEmail for business customers


    customers.push_back(
        new BusinessCustomer(
            Address("6 Beans Street", "Breda", "4000EF", "NL")
            , "Bean Bakers"
            , "Bart Bakker"
            , "bart@beanbakers.nl"
            )
    );

    customers.push_back(
        new BusinessCustomer(
            Address("7 Bacon Street", "Rotterdam", "3000GD", "NL")
            , "Beaconator"
            , "Fred flok"
            , "fredflok@beaconator.nl"
            )
    );

    customers.push_back(
        new BusinessCustomer(
            Address("9 Nein Street", "Berlin", "14199", "NL")
            , "Worst und peach"
            , "Liebe Luiten"
            , "lluiten@worstundpeach.de"
            )
    );


    // Create some harcoded packages

    std::vector<Package*> packages;

    // Add 3 packages to the array
    // Format is sender name, reciever name, sender addr, reciever addr, weight
    // Customers 1, 3, 4 and 6 are used. 2 and 5 are still unused
    packages.push_back(
        new TwoDayPackage(
            customers.at(0),
            customers.at(2),
            6.0
            )
        );

    packages.push_back(
        new OvernightPackage(
            customers.at(2),
            customers.at(3),
            7.0
            )
        );

    packages.push_back(
    new OvernightPackage(
        customers.at(3),
        customers.at(5),
        8.0
        )
    );


    // Lets first make a list of all businessCustomers they have
    std::vector<BusinessCustomer*> businessCustomers;

    for (Customer* customer : customers)
    {

        // Loop though them en add the customer to the list if they are business
        if (typeid(dynamic_cast<BusinessCustomer*>(customer)).name() == typeid(BusinessCustomer*).name()) {
            businessCustomers.push_back(dynamic_cast<BusinessCustomer*>(customer));
        }
    }

    // Loop though the packages and print the text if relevant
    for (auto package : packages) {
        // This function returns a tuple and thus must use 0 for corresponding customers and 1 for the remainder list
        auto resp = package->printChristmasCardContactPersons(businessCustomers);

        // update the remainder list
        businessCustomers = std::get<1>(resp);

        // send messages to found contact people
        for (auto cutomer : std::get<0>(resp)) {
            std::cout << "Merry Christmas " << cutomer->getName() << std::endl;
        }
    }




    // Lets print every package information and delete it
    for (auto pkg : packages)
    {
        std::cout << "Shipping cost for package "<< pkg->getInfo() << ": "<< pkg->calculateCost() << std::endl;
        delete pkg;
    }



    // Now let every customer print their information and delete it
    for (auto customer : customers)
    {
        customer->printCustomerInfo();
        delete customer;
    }

    return 0;
}

