//
// Created by josh on 3/9/26.
//

#include "address.h"

Address::Address(std::string n, std::string s, std::string c, std::string p, std::string co)
{
    buildingNumber = n;
    street = s;
    city = c;
    postcode = p;
    country = co;
}

std::string Address::toString() const
{
    return buildingNumber + " " + street + ", " + city + ", " + postcode + ", " + country;
}