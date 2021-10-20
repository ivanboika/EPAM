#include "Plane.h"
void Plane::Show() {
	std::cout << "\nAn total amount of passengers of "<<this->type <<" is "<< this->total_amount;
	std::cout << "\nPrise is " << this->prise;
}
void Plane::SetAmount(int amount) {
	this->total_amount = amount;
}
void Plane::SetPrise(int prise) {
	this->prise = prise;
}
void Plane::AverageAmount() {
	static double amount{ 0 };
	static int counter{ 0 };
	amount += this->GetAmount();
	counter++;
	std::cout << "\nAverage amount is " << amount / counter;
}
