#include "Exeptions.h"
double Func(int a, int b) {
	return a / b;
}
Fraction::Fraction(int a, int& b) {
	try {
		if (b == 0)
			throw STD runtime_error("\nYou can't divide on a zero");
	}
	catch (STD runtime_error& a) {
		STD cout << a.what();
		b = 1;
	}
}