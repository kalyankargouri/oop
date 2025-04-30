#include <iostream>
#include <vector>
#include <string>
#include <memory> 
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string make;
    string model;
    int year;
    bool isRented;
    double dailyRentalRate;

public:
    Vehicle(string id, string mk, string mdl, int yr, double rate)
        : vehicleID(id), make(mk), model(mdl), year(yr), isRented(false), dailyRentalRate(rate) {}

    string getVehicleID() const { return vehicleID; }
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    bool getIsRented() const { return isRented; }
    double getDailyRentalRate() const { return dailyRentalRate; }

    virtual double calculateRentalCost(int days) const = 0;
    virtual void displayDetails() const {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
        cout << "Daily Rental Rate: $" << dailyRentalRate << endl;
        cout << "Rented: " << (isRented ? "Yes" : "No") << endl;
    }

    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int numberOfDoors;
    string fuelType;

public:
    Car(string id, string mk, string mdl, int yr, double rate, int doors, string fuel)
        : Vehicle(id, mk, mdl, yr, rate), numberOfDoors(doors), fuelType(fuel) {}

    double calculateRentalCost(int days) const override {
        return dailyRentalRate * days;
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "-----------------------------" << endl;
    }
};

class Motorcycle : public Vehicle {
    string engineType;
    bool hasSidecar;

public:
    Motorcycle(string id, string mk, string mdl, int yr, double rate, string engine, bool sidecar)
        : Vehicle(id, mk, mdl, yr, rate), engineType(engine), hasSidecar(sidecar) {}

    double calculateRentalCost(int days) const override {
        return dailyRentalRate * days + (hasSidecar ? 20 * days : 0);
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Engine Type: " << engineType << endl;
        cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
        cout << "-----------------------------" << endl;
    }
};

class Truck : public Vehicle {
    double cargoCapacity;
    int numberOfAxles;

public:
    Truck(string id, string mk, string mdl, int yr, double rate, double capacity, int axles)
        : Vehicle(id, mk, mdl, yr, rate), cargoCapacity(capacity), numberOfAxles(axles) {}

    double calculateRentalCost(int days) const override {
        return dailyRentalRate * days + (cargoCapacity * 10 * days);
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Cargo Capacity: " << cargoCapacity << " cubic meters" << endl;
        cout << "Number of Axles: " << numberOfAxles << endl;
        cout << "-----------------------------" << endl;
    }
};

class RentalSystem {
private:
    vector<shared_ptr<Vehicle> > vehicles;

public:
    void addVehicle(shared_ptr<Vehicle> vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAvailableVehicles() const {
        bool anyAvailable = false;
        for (const auto& vehicle : vehicles) {
            if (!vehicle->getIsRented()) {
                vehicle->displayDetails();
                anyAvailable = true;
            }
        }
        if (!anyAvailable) {
            cout << "No vehicles available." << endl;
        }
    }

    shared_ptr<Vehicle> findVehicle(const string& vehicleID) const {
        for (const auto& vehicle : vehicles) {
            if (vehicle->getVehicleID() == vehicleID) {
                return vehicle;
            }
        }
        return nullptr;
    }

    void rentVehicle(const string& vehicleID, int days) {
        auto v = findVehicle(vehicleID);
        if (!v) {
            cout << "Vehicle not found!" << endl;
        } else if (v->getIsRented()) {
            cout << "Vehicle is already rented!" << endl;
        } else {
            v->rentVehicle();
            cout << "Rental Cost: $" << v->calculateRentalCost(days) << endl;
        }
    }

    void returnVehicle(const string& vehicleID) {
        auto v = findVehicle(vehicleID);
        if (!v) {
            cout << "Vehicle not found!" << endl;
        } else if (!v->getIsRented()) {
            cout << "Vehicle is not currently rented!" << endl;
        } else {
            v->returnVehicle();
            cout << "Vehicle returned successfully." << endl;
        }
    }
};

int main() {
    RentalSystem system;

    system.addVehicle(make_shared<Car>("CAR123", "Toyota", "Camry", 2020, 50.0, 4, "Petrol"));
    system.addVehicle(make_shared<Motorcycle>("MOTO456", "Yamaha", "MT-07", 2021, 30.0, "Inline-4", false));
    system.addVehicle(make_shared<Truck>("TRUCK789", "Ford", "F-150", 2019, 80.0, 15.0, 2));

    int choice;
    string id;
    int days;

    do {
        cout << "\n1. Display Available Vehicles\n";
        cout << "2. Rent a Vehicle\n";
        cout << "3. Return a Vehicle\n";
        cout << "4. Find Vehicle and Display Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            system.displayAvailableVehicles();
            break;
        case 2:
            cout << "Enter Vehicle ID: ";
            getline(cin, id);
            cout << "Enter number of days: ";
            cin >> days;
            cin.ignore();
            system.rentVehicle(id, days);
            break;
        case 3:
            cout << "Enter Vehicle ID: ";
            getline(cin, id);
            system.returnVehicle(id);
            break;
        case 4:
            cout << "Enter Vehicle ID: ";
            getline(cin, id);
            {
                auto v = system.findVehicle(id);
                if (v) v->displayDetails();
                else cout << "Vehicle not found!" << endl;
            }
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

