//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#include "../include/package.h"

Package::Package(std::string senderName, std::string receiverName, Address senderAddress, Address receiverAddress, double weight)
    :
    senderName(senderName),
    receiverName(receiverName),
    senderAddress(senderAddress),
    receiverAddress(receiverAddress),
    weight(weight)
{
}

// We need to calculate costs based on the formula
double Package::calculateCost() const
{
    double baseCost = 2.50 * weight + 5;
    // Don't forget to include additionalcosts that are "overridden" by the overnightPackage.
    return baseCost + additionalCost();
}

// We do actually have to return 0 if there's no additional costs
double Package::additionalCost() const
{
    return 0;
}
