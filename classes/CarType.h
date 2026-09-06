#ifndef CARTYPE_H
#define CARTYPE_H
#include <string>

enum class CarType {
    Compact,
    Midsize,
    Fullsize,
    SUV,
    Truck
};

std::string toString(CarType carType);
int getBaseRate(CarType carType);

#endif