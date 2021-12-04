#include "Customers.h"
int amount_of_accesses{ 0 };
Customers::Customers(int size) {
	try {
		if (size > 1500 || size < 0) {
			throw std::bad_array_new_length();
		}
		this->customers.resize(size); // default Buyer constructor 
		amount_of_accesses++; // resize
		for (int i{ 0 }; i < this->customers.size(); i++) {
			this->customers[i].Generator();
			amount_of_accesses++;
		}
	}
	catch (std::exception&excp) {
		std::cout << "\nBad array size";
		this->customers.resize(10);
		amount_of_accesses++;
	}
	catch (...) {
		std::cout << "\nUnpredicted error occured!";
	}
}
void Customers::Task() {
	std::sort(this->customers.begin(), this->customers.end(), [&](Buyer& a, Buyer& b) {if (a.GetBoughts() > b.GetBoughts()) { amount_of_accesses += 2; return true; } else { amount_of_accesses += 2; return false; } });
	int amount{ 0 };
	std::cout << "\nEnter how much customers do you want to deal with: "; std::cin >> amount;
	try {
		if (amount > 500 || amount < 0) {
			throw std::bad_array_new_length();
		}
	}
	catch (std::exception& excp) {
		amount = 10;
		std::cout << "\nBad array size";
	}
	catch (...) {
		amount = 10;
		std::cout << "\nUnpredicted error occured!";
	}
	for (int i{ 0 }; i < amount; i++) {
		this->customers[i].Show();
		amount_of_accesses += amount;
	}
	std::cout << "\nAmount of accesses is : " << amount_of_accesses;
	//static for amount of data accesses
}