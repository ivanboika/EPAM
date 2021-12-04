#pragma once
#include "Currency.h"
class EUR :virtual public Currency {
private:
	const float ratio = 0.002;
	const std::vector<std::string> type{ "EUR","eur","euro","EURO" };
public:

	EUR();
	EUR(float);
	void Show()override;
};
