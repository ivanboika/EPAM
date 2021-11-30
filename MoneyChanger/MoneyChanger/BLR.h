#pragma once
#include "Currency.h"
class BLR : public Currency {
private:
	const std::string type{ "BLR" };
	const float ratio = 0.0058;
public:
	BLR();
	BLR(float);
	void Show() override;
};