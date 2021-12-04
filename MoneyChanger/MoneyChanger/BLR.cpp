#include "BLR.h"
BLR::BLR(): Currency() {

}
BLR::BLR(float amount) : Currency(amount) {

}
void BLR::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount << std::endl;
}