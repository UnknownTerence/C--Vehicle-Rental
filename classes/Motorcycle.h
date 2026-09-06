#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
#include <string>

class Motorcycle : public Vehicle {
public:
    using Vehicle::Vehicle;
    std::string getVehicleType() const;
    float getDailyRate() const;
};

#endif