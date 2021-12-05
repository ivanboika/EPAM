#include "RUB.h"
RUB::RUB() : Currency() {}
RUB::RUB(float amount,float ratio) : Currency(amount,ratio) {}
void RUB::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount << std::endl;
}