#include "Customers.h"
Customers::Customers(int size) {
	try {
		if (size > 1500 || size < 0) {
			throw std::bad_array_new_length();
		}
		this->customers.resize(size);
		for (int i{ 0 }; i < this->customers.size(); i++) {
			this->customers[i].Generator();
		}
	}
	catch (std::exception&excp) {
		std::cout << "\nBad array size";

	}
	catch (...) {
		std::cout << "\nUnpredicted error occured!";
	}
}
void Customers::Task() {
	std::sort(this->customers.begin(), this->customers.end(), [](Buyer& a, Buyer& b) {if (a.GetBoughts() > b.GetBoughts())return true; else return false; });
	int amount{ 0 };
	std::cout << "\nEnter how much customers do you want to deal with: "; std::cin >> amount;
	try {
		if (amount > 500 || amount < 0) {
			throw std::bad_array_new_length();
		}
	}
	catch (std::exception& excp) {
		std::cout << "\nBad array size";
	}
	catch (...) {
		std::cout << "\nUnpredicted error occured!";
	}
	for (int i{ 0 }; i < amount; i++) {
		this->customers[i].Show();
	}
	//static for amount of data accesses
}