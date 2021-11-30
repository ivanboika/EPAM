#pragma once
#include "Currency.h"
class RUB : public Currency {
private:
	const std::string type{ "RUB" };
	const float ratio = 0.17;
public:
	RUB();
	RUB(float);
};

