//
// Created by josh on 3/9/26.
//

#ifndef LAB1_TWODAYPACKAGE_H
#define LAB1_TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package
{
    public:
    TwoDayPackage(std::string senderName, std::string receiverName, Address senderAddress, Address receiverAddress, double weight)
        : Package(senderName, receiverName, senderAddress, receiverAddress, weight) {}
};


#endif //LAB1_TWODAYPACKAGE_H