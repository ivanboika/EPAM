#include "libs.h"
#include "Buyer.h"
#include"Customers.h"
int main() {
	setlocale(LC_ALL, "rus");
	Customers all(10);
	all.Task();
	return 0;
}