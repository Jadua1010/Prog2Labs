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



int main(void) {

    // Create some hardcoded customers
/*    std::vector<Customer*> customers;


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
    );*/


    // Create some harcoded packages

    std::vector<Package*> packages;

    // Add 3 packages to the array
    // Format is sender name, reciever name, sender addr, reciever addr, weight
    packages.push_back(
        new TwoDayPackage(
            "John Doe",
            "Sam Smith",
            Address("1 Pie Street", "Enschede","1000AB", "NL"),
            Address("3 Sea Street", "Zaanstad","2000CD", "NL"),
            6.0
            )
        );

    packages.push_back(
        new OvernightPackage(
            "John Hoe",
            "Jan Smith",
            Address("6 Beans Street", "Breda","4000EF", "NL"),
            Address("7 Bacon Street", "Rotterdam","3000GD", "NL"),
            7.0
            )
        );

    packages.push_back(
    new OvernightPackage(
        "Bah Whet",
        "Johan Warm",
        Address("8 Oui Street", "Paris","45685", "FR"),
        Address("9 Nein Street", "Berlin","14199", "NL"),
        8.0
        )
    );

    for (auto pkg : packages)
    {
        std::cout << "Shipping cost for package "<< pkg->getInfo() << ": "<< pkg->calculateCost() << std::endl;
        delete pkg;
    }

    return 0;
}
