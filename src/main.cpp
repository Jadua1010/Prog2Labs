//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#include <iostream>
#include <vector>
#include "package.h"
#include "twoDayPackage.h"
#include "overnightPackage.h"

int main(void) {
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

    // Now loop through all the packages in the array and print the information about it.
    for (auto pkg : packages)
    {
        std::cout << "Shipping cost for package "<< pkg->getInfo() << ": "<< pkg->calculateCost() << std::endl;
        delete pkg;
    }

    return 0;
}
