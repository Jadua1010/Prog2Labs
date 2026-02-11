#include "person.h"
#include <iostream>
#include <chrono>

Person::Person(std::string _firstname, std::string _lastname, int day, int month, int year) {

    using namespace std::chrono;
    auto now = system_clock::now();           // 1. get time_point for now
    auto today = time_point_cast<days>(now);  // 2. cast to time_point for today
    auto ymd = year_month_day(today);         // 3. convert to year_month_day 
    auto currentYear = ymd.year();

    // Int validation

    if (day < 1 || day > 31)
        throw std::invalid_argument("Day is out of range");
    if (month < 1 || month > 12)
        throw std::invalid_argument("Month is out of range");
    if (year > static_cast<int>(currentYear))
        throw std::invalid_argument("Year is out of range");


    firstname = _firstname;
    lastname = _lastname;
    dobDay = day;
    dobMonth = month;
    dobYear = year;
}

int Person::getAge() {
    using namespace std::chrono;    
    auto now = system_clock::now();           // 1. get time_point for now
    auto today = time_point_cast<days>(now);  // 2. cast to time_point for today
    auto ymd = year_month_day(today);         // 3. convert to year_month_day 
    auto year = ymd.year();
    auto month = ymd.month();
    int monthInt = int(static_cast<unsigned>(month));
    auto day = ymd.day();
    int dayInt = int(static_cast<unsigned>(day));

    int correction = 0;

    if (monthInt < dobMonth || (monthInt = dobMonth && dayInt < dobDay))
        correction = 1;


    return (static_cast<int>(year) - dobYear - correction);
}

std::string Person::getFullName() {
    return firstname + " " + lastname;
}

std::string Person::getFullDob() {
    return std::to_string(dobDay).append(" - ").append(std::to_string(dobMonth)).append(" - ").append(std::to_string(dobYear));
}