#include"Exeptions.h"
//
// 
//
#define TYPE AviaTicket
int main() {
	int choice{ 1 };
	Queue<TYPE>* nums;
	nums = new Queue<TYPE>;
	int choice_type;
	while (choice != 0) {
		std::cout << "Choose: 1- Push objs,2- pop objs,3- check is empty,4-show, 5-find by id and date,6 pop by means of position: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			TYPE a;
			if (nums->first_time) {
				// for the first time
				std::cout << "\nEnter the date: ";
				std::cin.ignore(32767, '\n');
				std::getline(std::cin, a.date);
				std::cout << "Enter the endpoint: ";
				std::getline(std::cin, a.end);
				std::cout << "Enter the name: ";
				std::getline(std::cin, a.name);
				std::cout << "Enter the id: ";
				std::cin >> a.id;
				nums->Set(a);
				nums->first_time = false;
			}
			else {
				//others
				std::cout << "\nEnter the data: ";
				std::cin.ignore(32767, '\n');
				std::getline(std::cin, a.date);
				std::cout << "Enter the endpoint: ";
				std::getline(std::cin, a.end);
				std::cout << "Enter the name: ";
				std::getline(std::cin, a.name);
				std::cout << "Enter the id: ";
				std::cin >> a.id;
				nums->Push(nums, a);
			}
			break;
		}
		case 2: {
			Queue<TYPE>* temporary;
			temporary = nums->Pop();
			nums = temporary;
			temporary = nullptr;
			if (nums != nullptr && nums->first_time == true) { // 
				nums->LeftNullptr(); // clear left side of the first element
			}
			break;
		}
		case 3: {
			if (nums->Empty()) {
				std::cout << "\nQueue is empty\n";
			}
			else {
				std::cout << "\nQueue isn't empty\n";
			}
			break;
		}
		case 4: {
			nums->Show();
			break;
		}
		case 5: {
			std::string date;
			std::cout<< "\nEnter the date: ";
			std::cin.ignore(32767, '\n');
			std::getline(std::cin, date);
			std::cout << "\nEnter the id: ";
			int id{ 0 };
			std::cin >> id;
			std::cout << nums->Find(date, id) << std::endl;
			break;
		}
		case 6: {
			nums = nums->NewPop();
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
