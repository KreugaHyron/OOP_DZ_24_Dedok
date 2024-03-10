#include <iostream>
#include <string>
using namespace std;
class Transport {
protected:
    double cost;
    double fuel_consumption;
    double capacity;
    int seats;
public:
    Transport(double cost, double fuel_consumption, double capacity, int seats) :
        cost(cost), fuel_consumption(fuel_consumption), capacity(capacity), seats(seats) {}
    virtual ~Transport() {}
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual double getCost() const = 0;
    virtual void setCost(double cost) = 0;
    virtual double calculateFuelConsumption() const = 0;
    virtual double getCapacity() const = 0;
    virtual int getSeats() const = 0;
};
class Car : public Transport {
private:
    string model;
public:
    Car(string model, double cost, double fuel_consumption, double capacity, int seats) : Transport(cost, fuel_consumption, capacity, seats), model(model) {}
    void input() override {
		cout << "Enter car model: ";
		cin >> model;
	}
	void output() const override {
		cout << "Car model: " << model << endl;
	}
	double getCost() const override {
		return cost;
	}
	void setCost(double cost) override {
		this->cost = cost;
	}
	double calculateFuelConsumption() const override {
		return fuel_consumption;
	}
	double getCapacity() const override {
		return capacity;
	}
	int getSeats() const override {
		return seats;
	}
};
int main()
{
	const int size = 3;
	Transport* transports[size];
	transports[0] = new Car("Toyota Camry", 10000, 10, 5, 5);
	transports[1] = new Car("Nissan Leaf", 5000, 8, 5, 5);
	transports[2] = new Car("Volkswagen Passat", 8000, 12, 5, 5);
	for (int i = 0; i < size; ++i) {
		transports[i]->output();
		cout << "Total cost: " << transports[i]->getCost() << endl;
		cout << "Fuel consumption: " << transports[i]->calculateFuelConsumption() << endl;
		cout << "Capacity: " << transports[i]->getCapacity() << endl;
		cout << "Seats: " << transports[i]->getSeats() << endl;
		delete transports[i];
	}
	return 0;
}

