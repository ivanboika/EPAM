#include "D:\git\new_epam\DB_task\DB_task\libs.h"
#include "BLR.h"
#include "EUR.h"
#include "RUB.h"
#include "USD.h"
#include "Currency.h"
#include"funcs.h"
#include"tempClass.h"
//i hate this code, that's terrible, i don't wanna be father of this, ofc there is much better variat of decision
int main() {
	int choice{ 0 };
	std::vector<Currency*>values;
	std::string temp;
	std::vector<char>signs{ '+' };
	do {
		try {
			std::cout << "1-Enter amount of currency\n2-Enter the output type and calculate\n4-Clear the list\n5-Show\n";
			choice = _getch();
			switch (choice) {
			case '1': {
				std::cout << "\nEnter what u want to count(Ex: 35RUB+5USD+1EUR): ";
				std::cin.clear();
				std::getline(std::cin, temp);
				GetAll(temp, values, signs);
				temp.clear();
				break;
			}
			case'2': {
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
					result.CalcAll(values, signs);
					result.Show();
					break;
				}
				default: {
					std::cout << "\nYou missed";
					break;
				}
				}

				break;
			}
			case '4': {
				values.clear();
				values.resize(0);
				signs.resize(1);
				break;
			}
			case '5': {
				for (int i{ 0 }; i < values.size(); i++) {
					values[i]->Show();
				}
				break;
			}
			case 'n': {
				break;
			}
			default: {
				std::cout << "\nYou missed";
				break;
			}
			}
		}
		catch (std::exception& _exc) {
			std::cout << "\n" << _exc.what();
		}
	} while (choice != 'n');
	return 0;
}
