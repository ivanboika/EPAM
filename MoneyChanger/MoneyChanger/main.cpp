#include "H:\empty\DB_task\DB_task\libs.h"
#include "Currency.h"
#include "BLR.h"
#include "EUR.h"
#include "RUB.h"
#include "USD.h"
#include"funcs.h"
#include"UniqueCurr.h"
#include"tempClass.h"
//i hate this code, that's terrible, i don't wanna be father of this, ofc there is much better variat of decision
int main() {
	int choice{ 0 };
	std::vector<Currency*>values;
	std::string temp{ "" };
	std::vector<char>signs{ '+' };
	try {
		do {
			std::cout << "1-Enter amount of currency\n2-Enter the output type and calculate\n4-Clear the list\n5-Show\n";
			std::cin >> choice;
			switch (choice) {
			case 1: {
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
				case RUB_: {
					TempClass<RUB> result(0, type);
					result.CalcAll(values, signs);
					result.Show();
					break;
				}
				case USD_: {
					TempClass<USD> result(0, type);
					result.CalcAll(values, signs);
					result.Show();
					break;
				}
				case EUR_: {
					TempClass<EUR> result(0, type);
					result.CalcAll(values, signs);
					result.Show();
					break;
				}
				case BLR_: {
					TempClass<BLR> result(0, type);
					result.CalcAll(values,signs);
					result.Show();
					break;
				}
				default: {
					std::cout << "\nYou missed";
					break;
				}
				}
			}
			case 4: {
				values.clear();
				signs.clear();
				break;
			}
			case 5: {
				for (int i{ 0 }; i < values.size(); i++) {
					values[i]->Show();
				}
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
