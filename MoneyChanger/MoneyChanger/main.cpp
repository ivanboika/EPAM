#include "H:\empty\DB_task\DB_task\libs.h"
#include "Currency.h"
#include "BLR.h"
#include "EUR.h"
#include "RUB.h"
#include "USD.h"
#include"funcs.h"
//i hate this code, that's terrible, i don't wanna be father of this, ofc there is much better variat of decision
int main() {
	int choice{ 0 };
	std::vector<Currency*>values;
	std::string temp{ "" };
	std::vector<char>signs{ '+' };
	Currency* result;
	try {
		do {
			std::cout << "1-Enter amount of currency\n2-Enter the output type\n3-Calculate everything\n4-Clear the list\n";
			std::cin >> choice;
			switch (choice) {
			case 1: {
				/*int type{0};
				std::cout << "\nEnter type(1-RUB,2-USD,3-EUR,4-BLR):  ";
				std::cin >> type;
				switch (type) {
					float amount;
				case RUB_: {
					std::cout << "Enter amount: "; std::cin >> amount;
					values.push_back(new RUB(amount));
					break;
				}
				case USD_: {
					std::cout << "Enter amount: "; std::cin >> amount;
					values.push_back(new USD(amount));
					break;
				}
				case EUR_: {
					std::cout << "Enter amount: "; std::cin >> amount;
					values.push_back(new EUR(amount));
					break;
				}
				case BLR_: {
					std::cout << "Enter amount: "; std::cin >> amount;
					values.push_back(new BLR(amount));
					break;
				}
				default: {
					std::cout << "\nYou missed";
					break;
				}
				}*/
				std::cout << "\nEnter what u want to count(Ex: 35RUB+5USD+1EUR): ";
				std::cin.ignore(32767, '\n');
				std::getline(std::cin, temp);
				GetAll(temp, values, signs);
				break;
			}
			case 2: {
				int type{ 0 };
				std::cout << "\nEnter type(1-RUB,2-USD,3-EUR,4-BLR):  ";
				std::cin >> type;
				switch (type) {
					float amount;
				case RUB_: {
					result = new RUB();
					break;
				}
				case USD_: {
					result = new USD();
					break;
				}
				case EUR_: {
					result = new EUR();
					break;
				}
				case BLR_: {
					result = new BLR();
					break;
				}
				default: {
					std::cout << "\nYou missed";
					break;
				}
					   break;
				}
			}
			case 3: {
				values[0]->Show();
				try {
					for (int i{ 0 }; i < values.size(); i++) {
						if (signs[i] == '+') {
							
						}
					}
				}
				catch (...) {
					std::cout << "\nI suppose that u used 3 point without using 2 point";
				}
				break;
			}
			case 4: {
				values.clear();
				signs.clear();
				break;
			}
			default: {
				std::cout << "\nYou missed";
				break;
			}
			
			}
		} while (choice != 'n');
	}
	catch (std::exception& _exc) {
		std::cout << "\n" << _exc.what();
	}
	return 0;
}
