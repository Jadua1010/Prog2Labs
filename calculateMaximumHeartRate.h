#pragma once
#include "person.h"


class MaxHeartRate {
private:
    MaxHeartRate(int maxBPM);
    static void CalculateTargetHeartRates(MaxHeartRate& maxHeartRate);
public:
    int MaxBPM;
    int MinimumTarget;
    int MaximumTarget;
    static MaxHeartRate CalculateMaximumHeartRate(Person& person);
};

