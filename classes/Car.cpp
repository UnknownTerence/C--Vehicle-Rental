#include "Car.h"
#include <iostream>
#include <string>
#include "CarType.h"

Car::Car(const std::string& make, const std::string& model, int year, int mileage, const std::string& fuelType, const std::string& licensePlate, const CarType carType) : Vehicle(make, model, year, mileage, fuelType, licensePlate) {
    this->carType = carType;
}

std::string Car::getVehicleType() const {
    return toString(this->carType); // toString is in CarType
}

std::string Car::getCarType() const {
    return "CAR";
}

// every 10 000 km is $0.2 cheaper | every year from 2020 is $0.1 more/less
float Car::getDailyRate() const {
    return getBaseRate(this->carType) - (mileage * 0.00002) + (this->year - 2020) * 0.1;
}