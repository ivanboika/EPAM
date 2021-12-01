#include "Currency.h"
Currency::Currency() {
	this->amount = 0;
}
Currency::Currency(float amount) : amount(amount){
}
template <typename C>
C operator+(const C& obj) {
	return C(this->ratio*this->amount + obj.ratio*obj.amount);
}
template <typename C>
C operator-(const C& obj) {
	return C(this->ratio * this->amount - obj.ratio * obj.amount);
}
