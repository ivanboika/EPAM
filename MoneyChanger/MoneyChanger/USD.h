#pragma once
#include "Currency.h"
class USD : public Currency {
private:
	const float ratio = 0.0023;
	const std::vector<std::string> type{ "$","usd","USD" };
public:

	USD();
	USD(float, float ratio = 0.0023);
	void Show()override;
};

