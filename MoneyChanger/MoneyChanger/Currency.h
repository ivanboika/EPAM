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
	float amount;
public:

	Currency();
	Currency(float);
	virtual void Show() = 0;
	 template <typename C>
	 C operator+(C&);
	template <typename C>
	 C operator-(const C&);
};