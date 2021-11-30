#include "Currency.h"
Currency::Currency() {
	this->amount = 0;
}
Currency::Currency(float amount) {
	this->amount = 0;
}
template <typename C>
C operator+(const C& obj) {
	return C(this->amount + obj.amount);
}
template <typename C>
C operator-(const C& obj) {
	return C(this->amount - obj.amount);
}
