//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#ifndef LAB1_PACKAGE_H
#define LAB1_PACKAGE_H

#include <string>
#include "address.h"

class Package
{
// Use protected because we want these values to be accessible in derrived classes but NOT anywhere else
protected:
    std::string senderName;
    std::string receiverName;

    Address senderAddress;
    Address receiverAddress;

    double weight;

public:
    Package(std::string senderName, std::string receiverName, Address senderAddress, Address receiverAddress, double weight);

    // Make virtual, we want polymorphism
    double calculateCost() const;
    virtual double additionalCost() const;
    std::string getInfo() const {return senderName + " -> " + receiverName;};
};


#endif //LAB1_PACKAGE_H