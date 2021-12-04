#include "USD.h"
USD::USD() : Currency() {

}
USD::USD(float amount) : Currency(amount) {

}
void USD::Show() {
	std::cout << "\nType: " << this->type[0] << "\nAmount: " << this->amount<<std::endl;
}