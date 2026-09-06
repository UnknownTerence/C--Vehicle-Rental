#include "classes/Vehicle.h"
#include "classes/Car.h"
#include "classes/CarType.h"
#include "classes/Motorcycle.h"
#include <iostream>
#include <iomanip>
#include <vector>

/*
    NOTES FOR FUTURE AND PRESENT TERENCE

    when renting a vehicle, ask for a name, will be needed for returning as well

    ISSUE: NO MOTORCYCLES

    ISSUE: NO WAY TO RETURN VEHICLES

    ISSUE: NO USE OF SMART POINTERS (WHERE TO USE EM?)

    SUGGESTION: RANDOMIZE CAR GENERATION?

*/





/*
    Main Menu
    Prints out the text in the console for the main menu
*/
void mainMenu() {
    std::cout << "-------------------- Vehicle Rental Service --------------------" << std::endl;
    std::cout << "Hello customer, what type of vehicle are you looking for?" << std::endl;
    std::cout << "[1] Car" << std::endl;
    std::cout << "[2] Motorcycle" << std::endl;
    std::cout << "[3] Return Vehicle" << std::endl;
    std::cout << "[4] Quit" << std::endl;
}

/*
    Car Menu
    Prints of the text in the console and logic for printing out all the vehicles
    with basic information about them
*/
void vehicleMenu(const std::vector<Car>& carList, const std::string& menuTitle) {
    std::cout << "------------------------ "+ menuTitle +" Rental Menu ------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < carList.size(); i++) { // size_t is byte size, indexes are by byte sizes anyways (index * byte size = memory address), using int would cause implicit casts when using .at()
        std::cout << std::setw(5) <<"[" + std::to_string(i) + "] " << std::left << std::setw(30) << carList.at(i).getVehicleInfo();
        std::cout << "Daily Rate: $" << carList.at(i).getDailyRate() << std::endl;
        if (i == (carList.size() - 1)) {
            std::cout << "[" + std::to_string(i+1) + "] Back" << std::endl;
        }
    }
}
void vehicleMenu(const std::vector<Motorcycle>& motorcycleList, const std::string& menuTitle) {
    std::cout << "------------------------ "+ menuTitle +" Rental Menu ------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < motorcycleList.size(); i++) { // size_t is byte size, indexes are by byte sizes anyways (index * byte size = memory address), using int would cause implicit casts when using .at()
        std::cout << std::setw(5) <<"[" + std::to_string(i) + "] " << std::left << std::setw(30) << motorcycleList.at(i).getVehicleInfo();
        std::cout << "Daily Rate: $" << motorcycleList.at(i).getDailyRate() << std::endl;
        if (i == (motorcycleList.size() - 1)) {
            std::cout << "[" + std::to_string(i+1) + "] Back" << std::endl;
        }
    }
}

/*
    View Car
    Prints out all the information about the car and allows the user to rent
    or go back
*/
void viewVehicle(const std::vector<Car>& carList, int index) {
    std::cout << "----------------------- " + carList.at(index).getVehicleInfo() + " -----------------------" << std::endl;
    std::cout << "  Mileage: " << std::left << std::setw(30) << carList.at(index).getMileage();
    std::cout << "Daily Rate: $" << carList.at(index).getDailyRate() << "\n\n";
    std::cout << "[1] Rent Vehicle\n[2] Back" << std::endl;
}
void viewVehicle(const std::vector<Motorcycle>& motorcycleList, int index) {
    std::cout << "----------------------- " + motorcycleList.at(index).getVehicleInfo() + " -----------------------" << std::endl;
    std::cout << "  Mileage: " << std::left << std::setw(30) << motorcycleList.at(index).getMileage();
    std::cout << "Daily Rate: $" << motorcycleList.at(index).getDailyRate() << "\n\n";
    std::cout << "[1] Rent Vehicle\n[2] Back" << std::endl;
}

/*
    Update Rented Cars
    Updates the vector with which cars are rented out and removes them from the car list
    third var allows the user to either REMOVE from car list (vehicle rented), or ADD to
    car list (vehicle returned)
*/
void updateRentedVehicles(std::vector<Car>& carList, std::vector<Car>& rentedCarList) {
    for(size_t i = 0; i < carList.size();) {// interesting way to make a while loop with a counter
        if (carList.at(i).getRentStatus()) {
            rentedCarList.push_back(carList.at(i));
            carList.erase(carList.begin() + i); // removes that index, so it has to run it over again
        }
        else {
            i++;
        }
    }
}
void updateRentedVehicles(std::vector<Motorcycle>& motorcycleList, std::vector<Motorcycle>& rentedMotorcycleList) {
    for(size_t i = 0; i < motorcycleList.size();) {// interesting way to make a while loop with a counter
        if (motorcycleList.at(i).getRentStatus()) {
            rentedMotorcycleList.push_back(motorcycleList.at(i));
            motorcycleList.erase(motorcycleList.begin() + i); // removes that index, so it has to run it over again
        }
        else {
            i++;
        }
    }
}

void returnRentedVehicle(std::vector<Car>& carList, std::vector<Car>& rentedCarList, const std::string& name) {
    for(size_t i = 0; i < rentedCarList.size();) {
        if(rentedCarList.at(i).getCustomerName() == name) {
            rentedCarList.at(i).returnVehicle();
            carList.push_back(rentedCarList.at(i));
            rentedCarList.erase(rentedCarList.begin() + i);
        }
        else {
            i++;
        }
    }
}

void returnRentedVehicle(std::vector<Motorcycle>& motorcycleList, std::vector<Motorcycle>& rentedMotorcycleList, const std::string& name) {
    for(size_t i = 0; i < rentedMotorcycleList.size();) {
        if(rentedMotorcycleList.at(i).getCustomerName() == name) {
            rentedMotorcycleList.at(i).returnVehicle();
            motorcycleList.push_back(rentedMotorcycleList.at(i));
            rentedMotorcycleList.erase(rentedMotorcycleList.begin() + i);
        }
        else {
            i++;
        }
    }
}

/*
    Check Valid Integer
    Checks if the user input is of type int
*/
void checkInt(int& input) {
    while(true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // largest(max()) possible value for type streamsize
            std::cout << "Invalid Input" << std::endl;
        }
        else break;
    }
}

void checkString(std::string& name) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter your name" << std::endl;
    std::getline(std::cin, name);

}

int main() {
    std::vector<Car> carList;
    std::vector<Car> rentedCarList;
    carList.push_back(Car("Honda", "Civic", 2010, 213209, "gas", "CJWS542", CarType::Compact));
    carList.push_back(Car("Toyota", "Corolla", 2022, 50421, "gas", "DDAS237", CarType::Compact));
    carList.push_back(Car("Mazda", "CX5", 2023, 32763, "gas", "CHYV872", CarType::SUV));
    carList.push_back(Car("Ford", "F150", 2018, 97688, "gas", "BJKW923", CarType::Truck));
    carList.push_back(Car("Toyota", "Camry", 2019, 102813, "gas", "CMRP470", CarType::Midsize));

    std::vector<Motorcycle> motorcycleList;
    std::vector<Motorcycle> rentedMotorcycleList;
    motorcycleList.push_back(Motorcycle("Harley-Davidson", "FLHTK", 2018, 9924, "gas", "5G2G3"));

    // User input and menu handling
    int userInput;
    std::string name;

    while (true) {
        mainMenu();
        checkInt(userInput);
        if (userInput == 1) {
            while (true) {
                updateRentedVehicles(carList, rentedCarList);
                vehicleMenu(carList, "Car");
                checkInt(userInput);
                if (userInput >= 0 && userInput < carList.size()) {
                    while(true) {
                        int currentCar = userInput;
                        viewVehicle(carList, userInput);
                        checkInt(userInput);
                        if (userInput == 1) {
                            checkString(name);
                            carList.at(currentCar).rentVehicle(name);
                            std::cout << "VEHICLE RENTED!!!!!" << std::endl;
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        else if (userInput == 2) {
            while (true) {
                updateRentedVehicles(motorcycleList, rentedMotorcycleList);
                vehicleMenu(motorcycleList, "Motorcycle");
                checkInt(userInput);
                if (userInput >= 0 && userInput < motorcycleList.size()) {
                    while(true) {
                        int currentMotorcycle = userInput;
                        viewVehicle(motorcycleList, userInput);
                        checkInt(userInput);
                        if (userInput == 1) {
                            checkString(name);
                            motorcycleList.at(currentMotorcycle).rentVehicle(name);
                            std::cout << "VEHICLE RENTED!!!!!" << std::endl;
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        else if (userInput == 3) {
            while(true) {
                std::cout << "[1] Return Car" << std::endl << "[2] Return Motorcycle" << std::endl << "[3] Back" << std::endl;
                checkInt(userInput);
                if (userInput == 1) {
                    checkString(name);
                    returnRentedVehicle(carList, rentedCarList, name);
                }
                else if (userInput == 2) {
                    checkString(name);
                }
                else {
                    break;
                }
            }
        }
        else {
            break;
        }
    }


    return 0;
}