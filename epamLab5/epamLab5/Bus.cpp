#include "Bus.h"
void Bus::Show() {
	std::cout << "\nAn average amount of passengers of "<< this->type<<" is "<< this->total_amount;
	std::cout << "\nPrise is " << this->prise;
}
void Bus::SetAmount(int amount) {
	this->total_amount = amount;
}
void Bus::SetPrise(int prise) {
	this->prise = prise;
}
void Bus::AverageAmount() {
	static double amount{ 0 };
	static int counter{ 0 };
	amount += this->GetAmount();
	counter++;
	std::cout << "Average amount is " << amount / counter;
}