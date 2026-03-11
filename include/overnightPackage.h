//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#ifndef LAB1_OVERNIGHTPACKAGE_H
#define LAB1_OVERNIGHTPACKAGE_H
#include "package.h"


class OvernightPackage : public Package
{
    public:
    // Define the overnightpackage as a type of package
    OvernightPackage(std::string senderName, std::string receiverName, Address senderAddress, Address receiverAddress, double weight)
        : Package(senderName, receiverName, senderAddress, receiverAddress, weight) {}

    // Function to "override" the additional cost value from the default package
    double additionalCost() const override
    {
        // The formula
        return 1.10 * weight * weight;
    }
};



#endif //LAB1_OVERNIGHTPACKAGE_H