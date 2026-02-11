//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 1.3
//=====================...........................=================================


// The code needs to do 220BPM - age => 100% heart rate
// Healthy range is 50% - 85% 

#include <iostream>
#include "person.h"
#include "calculateMaximumHeartRate.h"


int main(void) {
    // Code goes here

    Person person("", "", 1, 1, 2000);

    std::string firstname;
    std::cout << "Enter your first name:";
    std::cin >> firstname;

    std::string lastname;
    std::cout << "Enter your last name:";
    std::cin >> lastname;

    int dobDay;
    std::cout << "Enter your date of birth (day):";
    std::cin >> dobDay;

    int dobMonth;
    std::cout << "Enter your date of birth (month):";
    std::cin >> dobMonth;

    int dobYear;
    std::cout << "Enter your date of birth (year):";
    std::cin >> dobYear;



    try {
        person = Person(firstname, lastname, dobDay, dobMonth, dobYear);
    }
    catch (const std::exception& e) {
        std::cout << "Error occurred: " << e.what() << std::endl;
        return 0;
    }

    std::cout << "Your name is: " << person.getFullName() << std::endl;

    std::cout << "Your date of birth is: " << person.getFullDob() << std::endl;

    std::cout << "Your age is: " << person.getAge() << std::endl;

    MaxHeartRate heartRateInformation = MaxHeartRate::CalculateMaximumHeartRate(person);

    std::cout << "Max heart rate: " << heartRateInformation.MaxBPM << std::endl;
    std::cout << "Maximum targetted heart rate (85%): " << heartRateInformation.MaximumTarget << std::endl;
    std::cout << "Minimal targetted heart rate (50%): " << heartRateInformation.MinimumTarget << std::endl;

    return 0;
}