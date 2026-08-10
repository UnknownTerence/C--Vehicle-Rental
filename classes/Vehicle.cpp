#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() {
    std::cout << " default vehicle constructor!";
}
Vehicle::Vehicle(int num) {
    this->num = num;
}
int Vehicle::hey() {
    return this->num;
}