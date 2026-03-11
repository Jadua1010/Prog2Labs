//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#include "../include/address.h"

// Setup address of type string
Address::Address(std::string s, std::string c, std::string p, std::string co)
{
    street = s;
    city = c;
    postcode = p;
    country = co;
}

std::string Address::toString() const
{
    // Function that returns the address as 1 string
    return street + ", " + city + ", " + postcode + ", " + country;
}