#pragma once
#include "Currency.h"
class RUB : public Currency {
private:
	const float ratio = 0.17;
	const std::vector<std::string> type{ "RUB","rub" };
public:

	RUB();
	RUB(float);
	void Show()override;
};

