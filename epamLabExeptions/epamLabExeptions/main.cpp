#include"Exeptions.cpp"
#define TYPE int
int main() {
	int choice{ 1 };
	Queue<TYPE>* nums;
	nums = new Queue<TYPE>;
	int choice_type;
	bool first_time{ false };
	while (choice != 0) {
		std::cout << "Choose: 1- Push objs,2- pop objs,3- check is empty,4-show: ";
		std:: cin >> choice;
		switch (choice) {
		case 1: {
			TYPE a;
			if (!first_time) {
				std::cout << "Enter the value: ";
				std::cin >> a;
				nums->Set(a);
				first_time = true;
			}
			else {
				std::cout << "Enter the value: ";
				std::cin >> a;
				nums->Push(nums, a);
			}
			break;
		}
		case 2: {
			nums->Pop();
			break;
		}
		case 3: {
			if (nums->Empty()) {
				std::cout << "\nQueue is empty";
			}
			else {
				std::cout << "\nQueue isn't empty";
			}
			break;
		}
		case 4: {
			nums->Show();
			break;
		}
		case 7: { // put into another expection task project
			int dividend{ 0 }, divider{ 0 };
			std:: cout << "\nEnter dividend: ";
			std:: cin >> dividend;
			assert(!isalnum(dividend));
			std::cout << "Enter divider: ";
			std:: cin >> divider;
			assert(!isalnum(divider));
			Fraction a(dividend, divider);
			Func(dividend, divider);
			break;
		}
		default: {
			std::cout << "\nYou missed";
			break;
		}
		}
	}
	return 0;
}
