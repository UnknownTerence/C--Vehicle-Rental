#include "Vehicle.h"
#include <string>
// const vars allow the use of literal values with pass by reference
Vehicle::Vehicle(const std::string& make, const std::string& model, int year, int mileage, const std::string& fuelType, const std::string& licensePlate) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->mileage = mileage;
    this->fuelType = fuelType;
    this->licensePlate = licensePlate;
    this->isRented = false;
}

std::string Vehicle::getVehicleInfo() const {
    return std::to_string(year) + " " + make + " " + model;
}

int Vehicle::getMileage() const {
    return this->mileage;
}

void Vehicle::rentVehicle(const std::string& customer) {
    this->isRented = true;
    this->customer = customer;
}

void Vehicle::returnVehicle() {
    this->isRented = false;
}

bool Vehicle::getRentStatus() const {
    return this->isRented;
}

std::string Vehicle::getCustomerName() const {
    return this->customer;
}