#include "person.h"
#include <iostream>
#include "calculateMaximumHeartRate.h"
#include <cmath>

MaxHeartRate::MaxHeartRate(int maxHeartRate) {
    MaxBPM = maxHeartRate;

    MaxHeartRate::CalculateTargetHeartRates(*this);
}

void MaxHeartRate::CalculateTargetHeartRates(MaxHeartRate& maxHeartRate) {
    maxHeartRate.MinimumTarget = static_cast<int>(round(0.5 * maxHeartRate.MaxBPM));
    maxHeartRate.MaximumTarget = static_cast<int>(round(0.85 * maxHeartRate.MaxBPM));
}


MaxHeartRate MaxHeartRate::CalculateMaximumHeartRate(Person& person) {
    int age = person.getAge();
    int max = 220 - age;
    return MaxHeartRate(max);
}