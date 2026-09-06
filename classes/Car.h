#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "CarType.h"
#include <string>

class Car : public Vehicle {
public:
    Car(const std::string& make, const std::string& model, int year, int mileage, const std::string& fuelType, const std::string& licensePlate, const CarType carType);
    std::string getVehicleType() const;
    std::string getCarType() const;
    float getDailyRate() const;
protected:
    CarType carType;
    
};

#endif