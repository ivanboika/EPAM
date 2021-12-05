#include "USD.h"
USD::USD() : Currency() {}
USD::USD(float amount,float ratio) : Currency(amount,ratio) {}
void USD::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount<<std::endl;
}