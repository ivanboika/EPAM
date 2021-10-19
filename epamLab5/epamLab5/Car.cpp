#include "Car.h"
void Car::Show() {
	std::cout << "\nAn average amount of weight of  " << this->type << " is " << this->weight;
	std::cout << "\nPrise per kg is " << this->prise_for_kg;
}
void Car::SetWeight(int weight) {
	this->weight = weight;
}
void Car::TotalPrise(int smth) {
	std::cout << "Total prise of transport is" << this->prise_for_kg * this->weight;
}