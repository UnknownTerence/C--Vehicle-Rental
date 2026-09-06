#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle {
public: // const vars allow the use of literal values with pass by reference
    Vehicle(const std::string& make, const std::string& model, int year, int mileage, const std::string& fuelType, const std::string& licensePlate);
    std::string getVehicleInfo() const;
    int getMileage() const;
    void rentVehicle(const std::string& customer);
    void returnVehicle();
    bool getRentStatus() const;
    std::string getCustomerName() const;
protected:
    std::string make, model, fuelType, licensePlate, customer;
    int year, mileage;
    bool isRented;
};

#endif