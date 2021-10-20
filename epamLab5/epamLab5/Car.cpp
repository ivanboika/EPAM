#include "Car.h"
void Car::Show() {
	std::cout << "\nAn average amount of weight of  " << this->type << " is " << this->weight;
	std::cout << "\nPrise per kg is " << this->prise_for_kg;
}
void Car::SetWeight(int weight) {
	this->weight = weight;
}
void Car::TotalPrise() {
	std::cout << "\nTotal prise of transport is " << this->prise_for_kg * this->weight;
}
void Show(std::vector<Car>&obj) {
	for (int i{ 0 }; i < obj.size(); i++) {
		obj[i].Show();
	}
}
