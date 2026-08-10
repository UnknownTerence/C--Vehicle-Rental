#include "classes/Vehicle.h"
#include "classes/Car.h"
#include <iostream>

int main() {
    std::cout << "hello";

    Vehicle test; // already calls the default constructor
    Vehicle test2(5);

    std::cout << std::endl << test.hey();
    std::cout << std::endl << test2.hey();

    Car carTest;
    std:: cout << std::endl;
    carTest.getVehicleType();





    return 0;
}