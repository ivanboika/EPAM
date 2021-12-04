#pragma once
#include "H:\empty\DB_task\DB_task\libs.h"
enum CURR {
	RUB_ = 1,
	USD_,
	EUR_,
	BLR_
};
class Currency abstract {
protected:
	const float ratio = 0;
public:
	float amount;
	Currency();
	Currency(float);
	virtual void Show() = 0;
	Currency& operator+(Currency* obj);
};