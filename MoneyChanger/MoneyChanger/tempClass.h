#pragma once
#include "Currency.h"
#include"funcs.h"
template<typename T>
class TempClass:public Currency  {
private:
	Currency* value;
	const float ratio[4] = { 0.17 ,0.0023 ,0.002 ,0.0058 };
	int type;
public:
	TempClass(float amount, int type) :type(type - 1) {
	value = new T(amount);
	}
	/*T* GetMemory(int type, float amount) {
		switch (type) {
		case RUB_: {
			return new RUB(amount);
			break;
		}
		case USD_: {
			return new USD(amount);
			break;
		}
		case EUR_: {
			return new EUR(amount);
			break;
		}
		case BLR_: {
			return new BLR(amount);
			break;
		}
		default: {
			std::cout << "\nYou missed";
			return nullptr;
			break;
		}
		}
	}*/
	void Show()override {
		std::cout << "\nType: " << "" << "\nAmount: " << this->amount << std::endl;
	}
	void CalcAll(std::vector<Currency*> values, std::vector<char>& signs) {
		for (int i{ 0 }; i < values.size(); i++) {
			if (signs[i] == '+') {
				this->value->amount = this->value->amount + ((values[0]->amount)/this->ratio[this->type]);
			}
			else {
				this->value->amount = this->value->amount - ((values[0]->amount) / this->ratio[this->type]);
			}
		}
	}
	~TempClass() {
		delete this->value;
		type = 0;
	}
};

