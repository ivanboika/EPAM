#pragma once
#include "Goods.h"
class Car : public Goods {
private:
	std::string type;
public:
	Car(int prise , int weight ) : Goods(prise, weight) {}
	 inline void Show() override;
	 inline void SetWeight(int) override;
	 inline void TotalPrise() override;
	 friend inline void Show(std::vector<Car>&);
};

