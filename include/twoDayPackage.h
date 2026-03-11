//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#ifndef LAB1_TWODAYPACKAGE_H
#define LAB1_TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package
{
    // Public class that is of type package
    public:
    TwoDayPackage(std::string senderName, std::string receiverName, Address senderAddress, Address receiverAddress, double weight)
        : Package(senderName, receiverName, senderAddress, receiverAddress, weight) {}
};


#endif //LAB1_TWODAYPACKAGE_H