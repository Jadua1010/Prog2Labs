//
// Created by josh on 3/9/26.
//

#include "package.h"
#include "Customer.h"

Package::Package(Customer* _sender, Customer* _receiver, double weight)
    :
    sender(_sender),
    receiver(_receiver),
    weight(weight)
{
    if (_sender == _receiver)
        throw std::invalid_argument("Sender and receiver cant be the same");
}

double Package::calculateCost() const
{
    double baseCost = 2.50 * weight + 5;
    return baseCost + additionalCost();
}

// We do actually have to return 0 if there's no additional costs
double Package::additionalCost() const
{
    return 0;
}
