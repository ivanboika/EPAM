#include "RUB.h"
RUB::RUB() : Currency() {

}
RUB::RUB(float amount) : Currency(amount) {

}
void RUB::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount;
}