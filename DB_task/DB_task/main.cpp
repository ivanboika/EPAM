#include "libs.h"
#include "Buyer.h"
#include"Customers.h"
// ask what better - use temp value for size or get access to size from methods every time in for/any cycle
int main() {
	setlocale(LC_ALL, "rus");
	Buyer b(std::move(Buyer("aasd", "aba", 1, 2))); //works
	Customers all(1432);
	all.Task();
	return 0;
}