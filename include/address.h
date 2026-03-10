//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.2
//=====================...........................=================================

#ifndef LAB1_ADDRESS_H
#define LAB1_ADDRESS_H

#include <string>

class Address
{
    // Basic address with
    private:
        std::string street;
        std::string city;
        std::string postcode;
        std::string country;
    public:
        Address(std::string street, std::string city, std::string postcode, std::string country);

    std::string toString() const;

};

#endif //LAB1_ADDRESS_H