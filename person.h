#pragma once
#include <string>

class Person {
private:
    std::string firstname;
    std::string lastname;
    int dobDay;
    int dobMonth;
    int dobYear;

public:
    Person(std::string firstname, std::string lastname, int day, int month, int year);

    int getAge();

    std::string getFullName();
    std::string getFullDob();
};