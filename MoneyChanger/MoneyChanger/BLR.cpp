#include "BLR.h"
BLR::BLR(): Currency() {}
BLR::BLR(float amount, float ratio) : Currency(amount,ratio) {}
void BLR::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount << std::endl;
}