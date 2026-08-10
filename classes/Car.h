#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

class Car : public Vehicle {
public:
    const std::string VEHICLE_TYPE = "CAR";
    void getVehicleType();
};

#endif