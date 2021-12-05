#include "Currency.h"
Currency::Currency() {
	this->amount = 0;
}
Currency::Currency(float amount,float ratio) : amount(amount),ratio(ratio){
}