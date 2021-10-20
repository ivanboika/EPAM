#pragma once
#include "Transporter.h"
class Passenger : public Transporter {
protected:
	unsigned int total_amount;
	int prise;
public:
	Passenger(int amount, int prise) : total_amount(amount), prise(prise) {}
	inline virtual void Transporter::Show() = 0;
	inline virtual void SetAmount(int) = 0;
	inline virtual void SetPrise(int) = 0;
	inline virtual void AverageAmount() = 0;
	int GetAmount();
	inline int GetPrise();
};

