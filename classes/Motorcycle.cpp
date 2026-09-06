#include "Motorcycle.h"
#include <iostream>
#include <string>

std::string Motorcycle::getVehicleType() const {
    return "MOTORCYCLE";
}

// every 10 000 km is $0.2 cheaper | every year from 2020 is $0.1 more/less
float Motorcycle::getDailyRate() const {
    return 10.0;
}