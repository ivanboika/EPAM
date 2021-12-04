#pragma once
#include "Buyer.h"
#include"libs.h"
class Customers {
private:
	std::vector<Buyer>customers;
public:
	Customers(Customers&) = default;
	Customers(Customers&&) = default;
	Customers& operator=(const Customers&) = default;
	Customers& operator=(Customers&&) = default;
	~Customers() = default;
	Customers(int);
	void Task();
};