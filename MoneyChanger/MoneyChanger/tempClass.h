#pragma once
#include "Currency.h"
#include"funcs.h"
template<typename T>
class TempClass: public Currency  {
private:
	Currency* value;
	const float ratio[4] = { 0.17 ,0.0023 ,0.002 ,0.0058 };
	int type;
public:
	TempClass(float amount, int type) :type(type - 1) {
	value = new T(amount);
	}
	void Show()override {
		std::cout << "\nType: " << "chosen" << "\nAmount: " << this->value->amount << std::endl;
	}
	void CalcAll(std::vector<Currency*>& values, std::vector<char>& signs) {
		for (int i{ 0 }; i < values.size(); i++) {
			if (signs[i] == '+') {
				this->value->amount = this->value->amount + (((values[i]->amount) / values[i]->ratio) * this->ratio[type]);
			}
			else {
				this->value->amount = this->value->amount - (((values[i]->amount) / values[i]->ratio) * this->ratio[type]);
			}
		}
	}
	~TempClass() {
		delete this->value;
		type = 0;
	}
};

