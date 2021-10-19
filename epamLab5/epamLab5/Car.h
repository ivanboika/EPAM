#pragma once
#include "Goods.h"
class Car : public Goods {
private:
	std::string type;
public:
	Car(int prise = 0, int weight = 0, std::string type = "Car") :type(type) {}
	 void Show() override;
	 void SetWeight(int) override;
	 void TotalPrise(int) override;
};

