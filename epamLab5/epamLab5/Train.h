#pragma once
#include "Goods.h"
class Train : public Goods {
private:
	std::string type;
public:
	Train(int prise=0, int weight=0, std::string type= "Train") :Goods(prise,weight),type(type){}
	inline void Show() override;
	inline void SetWeight(int) override;
	inline void TotalPrise() override;
};

