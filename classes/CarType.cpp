#include "CarType.h"

std::string toString(CarType carType) {
    switch(carType) {
        case CarType::Compact:  return "Compact";
        case CarType::Midsize:  return "Midsize";
        case CarType::Fullsize: return "Fullsize";
        case CarType::SUV:      return "SUV";
        case CarType::Truck:    return "Truck";
        default:                return "Unknown";
    }
}

int getBaseRate(CarType carType) {
    switch(carType) {
        case CarType::Compact:  return 25;
        case CarType::Midsize:  return 40;
        case CarType::Fullsize: return 50;
        case CarType::SUV:      return 55;
        case CarType::Truck:    return 60;
        default:                return 0;
    }
}