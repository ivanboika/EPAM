#pragma once
#include "Currency.h"
class EUR : public Currency {
private:
	const std::string type{ "EUR" };
	const float ratio = 0.002;
public:
	EUR();
	EUR(float);
};

