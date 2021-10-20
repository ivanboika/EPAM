#include "Train.h"
void Train::Show() {
	std::cout << "\nAn average weight of " << this->type << " is " << this->weight;
	std::cout << "\nPrise per ks is " << this->prise_for_kg;
}
void Train::SetWeight(int weight) {
	this->weight = weight;
}
void Train::TotalPrise() {
	std::cout << "Total prise of transport is" << this->prise_for_kg * this->weight;
}