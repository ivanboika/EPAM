#pragma once
#include "D:\git\new_epam\DB_task\DB_task\libs.h"
enum CURR {
	RUB_ = 1,
	USD_,
	EUR_,
	BLR_
};
class Currency abstract {
public:
	float amount;
	float ratio;
	Currency();
	Currency(float, float);
	virtual void Show() = 0;
};