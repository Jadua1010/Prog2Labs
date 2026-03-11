//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_OVERNIGHTPACKAGE_H
#define LAB1_OVERNIGHTPACKAGE_H
#include "package.h"


class OvernightPackage : public Package
{
    public:
    OvernightPackage(Customer* sender, Customer* receiver, double weight)
        : Package(sender, receiver, weight) {}

    double additionalCost() const override
    {
        return 1.10 * weight * weight;
    }
};



#endif //LAB1_OVERNIGHTPACKAGE_H