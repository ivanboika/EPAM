#pragma once
#include "Passenger.h"
class Bus : public Passenger {
private:
	std::string type;
public:
	Bus(int amount = 1, int prise = 0, std::string type = "Bus") :type(type), Passenger(amount, prise) {}
	inline void Transporter::Show();
	inline void SetAmount(int) override;
	inline void SetPrise(int) override;
	inline void AverageAmount() override;
};

