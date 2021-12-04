#pragma once
#include "Currency.h"
class BLR :virtual public Currency {
private:
	const std::vector<std::string> type{ "BLR","blr","BYR","byr" };
	const float ratio = 0.0058;
public:
	BLR();
	BLR(float);
	void Show() override;
};