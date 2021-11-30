#pragma once
#include "Currency.h"
class USD : public Currency {
private:
	const std::string type{ "USD" };
	const float ratio = 0.0023;
public:
	USD();
	USD(float);
};

