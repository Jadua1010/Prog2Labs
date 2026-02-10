//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 1.2
//=====================...........................=================================

#include <iostream>
#include <cmath>

double under = 18.5;
double normal = 25;
double over = 30;

double divide(const double num, const double den) {
    return num/pow(den, 2);
}

void printInfo() {
    std :: cout << "BMI VALUES:\nUnderweight: less than " << under << std::endl
    << "Normal: between " << under << " and " << normal << std::endl
    << "Overweight: between " << normal << " and " << over << std::endl
    << "Obese: " << over << " or greater" << std::endl;
}

void evaluateAndPrintBMI (const double bmi){
    std :: cout << "Your BMI is: " << bmi << "\n" << "You are ";
    if (bmi < under) {
        std :: cout << "underweight" << std::endl;
    }
    else if (bmi < normal) {
        std :: cout << "normal weight" << std::endl;
    }
    else if (bmi < over) {
        std :: cout << "overweight" << std::endl;
    }
    else {
        std :: cout << "obese" << std::endl;
    }
}

int main(void) {
    double weight, height;

    printInfo();

    std::cout << "How wide are you (kg): ";
    std::cin >> weight;

    std::cout << "How long are you (m): ";
    std::cin >> height;

    double bmi = divide(weight, height);

    evaluateAndPrintBMI(bmi);

    return 0;
}