#include "Bag.h"
void Bag::show() const{
	std::cout << "Prise is " << this->prise << ", weight is " << this->weight << ", ratio is " << this->ratio << std::endl;
}
void show(const std::vector<Bag>& obj) {
	for (int i{ 0 }; i < obj.size(); i++)
		obj[i].show();
}
Bag::Bag(const Bag&obj) {
	this->prise = obj.prise;
	this->ratio = obj.ratio;
	this->weight = obj.weight;
}
Bag::Bag() {
	this->prise = 0;
	this->weight = 0;
	this->ratio = 0;
}
void assign(std::vector<Bag>&obj) {
	int prise{ 0 }, weight{ 0 };
	for (int i{ 0 }; i < obj.size(); i++) {
		prise = 2 + rand() % 50;
		weight = 10 + rand() % 100;
		obj[i] = Bag(prise, weight);
		obj[i].ratio = obj[i].weight / obj[i].prise;
	}
}
 const double Bag::getRatio()const  { return this->ratio; }
Bag& Bag::operator=(const Bag& obj) {
	this->prise = obj.prise;
	this->ratio = obj.ratio;
	this->weight = obj.weight;
	return *this;
}
double Bag::getWeight() const { return this->weight; }