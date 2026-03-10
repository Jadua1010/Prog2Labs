//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 4.1
//=====================...........................=================================

#include "../include/address.h"

Address::Address(std::string s, std::string c, std::string p, std::string co)
{
    street = s;
    city = c;
    postcode = p;
    country = co;
}

std::string Address::toString() const
{
    return street + ", " + city + ", " + postcode + ", " + country;
}