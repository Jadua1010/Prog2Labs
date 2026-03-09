//
// Created by josh on 3/9/26.
//

#include "address.h"

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