#pragma once
#include "Goods.h"
class Train : public Goods {
private:
	std::string type;
public:
	Train(int prise=0, int weight=0, std::string type= "Train") :Goods(prise,weight),type(type){}
	void Show() override;
	void SetWeight(int) override;
	void TotalPrise(int) override;
};

