#pragma once
#include "Passenger.cpp"
class Plane : public Passenger {
private:
	std::string type;
public:
	Plane(int amount = 0, int prise = 1, std::string type = "Plane") : type(type),Passenger(amount,prise) {}
	inline void Show() override;
	inline void SetAmount(int) override;
	inline void SetPrise(int) override;
	inline void AverageAmount() override;
};

