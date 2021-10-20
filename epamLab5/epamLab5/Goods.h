#pragma once
#include "Transporter.h"
class Goods : public Transporter {
protected:
	unsigned int weight;
	unsigned int prise_for_kg;
public:
	Goods(int prise, int weight_) : weight(weight_), prise_for_kg(prise) {}
	inline virtual void Goods::Transporter::Show() = 0;
	inline virtual void SetWeight(int) = 0;
	inline virtual void TotalPrise() = 0;
};

