//
// Created by josh on 3/9/26.
//

#ifndef LAB1_ADDRESS_H
#define LAB1_ADDRESS_H

#include <string>

class Address
{
    // Basic address with
    private:
        std::string buildingNumber;
        std::string street;
        std::string city;
        std::string postcode;
        std::string country;
    public:
        Address(std::string buildingNumber, std::string street, std::string city, std::string postcode, std::string country);

    std::string toString() const;

};

#endif //LAB1_ADDRESS_H