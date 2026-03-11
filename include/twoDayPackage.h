//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_TWODAYPACKAGE_H
#define LAB1_TWODAYPACKAGE_H

#include "package.h"
#include "Customer.h"

class TwoDayPackage : public Package
{
    public:
    TwoDayPackage(Customer* sender, Customer* receiver, double weight)
        : Package(sender, receiver, weight) {}
};


#endif //LAB1_TWODAYPACKAGE_H