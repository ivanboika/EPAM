#pragma once
#include "H:\empty\DB_task\DB_task\libs.h"
enum CURR {
	RUB = 1,
	USD,
	EUR,
	BLR
};
class Currency abstract {
protected:
	float amount;
	const float ratios[4] = { 0.17,0.0023,0.0020,0.0058 };
public:
	Currency();
	Currency(float);
	virtual void Show() = 0;
	 template <typename C>
	 C operator+(const C&);
	template <typename C>
	 C operator-(const C&);
	 int GetType();
};