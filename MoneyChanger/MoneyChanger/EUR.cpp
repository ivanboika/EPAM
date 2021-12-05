#include "EUR.h"
EUR::EUR() : Currency() {}
EUR::EUR(float amount, float ratio) : Currency(amount, ratio) {}
void EUR::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount<<std::endl;
}