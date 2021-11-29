#pragma once
class Currency abstract {
protected:
	float amount;
public:
	Currency();
	Currency(float);
	virtual void Show() = 0;
};

