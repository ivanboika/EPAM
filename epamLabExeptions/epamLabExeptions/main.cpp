#include"Exeptions.h"
int main() {
	int choice{ 1 };
	while (choice != 0) {
		STD cin >> choice;
		switch (choice) {
		case 7: { // put into another expection task project
			int dividend{ 0 }, divider{ 0 };
			STD cout << "\nEnter dividend: ";
			STD cin >> dividend;
			assert(!isalnum(dividend));
			STD cout << "Enter divider: ";
			STD cin >> divider;
			assert(!isalnum(divider));
			Fraction a(dividend, divider);
			Func(dividend, divider);
			break;
		}
		}
	}
	return 0;
}
