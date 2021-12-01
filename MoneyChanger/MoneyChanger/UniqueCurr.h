#pragma once
#include "Currency.h"
class UniqueCurr : public Currency {
private:
	const float ratio = 1;
public:
	UniqueCurr() :Currency() {};
	UniqueCurr(float obj) :Currency(obj) {};

};

