#pragma once
#include "Transporter.h"
class Goods : public Transporter {
protected:
	unsigned int weight;
	unsigned int prise_for_kg;
public:
	Goods(int prise=0, int weight_ = 0) {
		try {
			throw (weight_ < 0);
			this->weight = weight_;
		}
		catch (bool) {
			std::cout << "Amount of goods can not be lower than a zero!" << std::endl;
			this->weight = 0;
		};
	}
	virtual void Goods::Transporter::Show() = 0;
	virtual void SetWeight(int) = 0;
	virtual void TotalPrise(int) = 0;
};

