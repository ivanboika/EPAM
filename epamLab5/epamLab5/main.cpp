#include"Plane.cpp"
#include"Train.cpp"
#include"Car.cpp"
#include"Bus.cpp"
#include<ctime>
#include<conio.h>
#define EXIT 'n'
int main() {
	char choice{ 'y' };
	setlocale(0, "rus");
	do {
		std::cout << "\nTap 1 for Plane, tap 2 for Bus, tap 3 for Car, tap 4 for Train, tap n for exit "; choice = _getche();
		switch (choice) {
		case '1': {
			Plane plane1(54, 5, "Belavia");
			plane1.Show();
			std::vector<Plane>planes{ (54,2),(24,4),(52,9),(60,7),(12,3) };
			planes[0].Show();
			for (int i{ 0 }; i < planes.size(); i++) {
				planes[i].AverageAmount();
			}
			break;
		}
		case '2': {
			//task at the lesson (num 1)
			std::vector<int>first{ 5,1,8,4,3,7,10,12,54,23,42 };
			std::vector<int>second;
			second.assign(first.begin() + first.size() / 2, first.end());
			std::cout << std::endl;
			for (int i{ 0 }; i < second.size(); i++)
				std::cout << second[i] << " ";
			break;
		}
		case '3': {
			std::vector<Car>cars;
			int prise{ 0 }, weight{ 0 };
			for (int i{ 0 }; i < 5; i++) {
				prise = 1 + rand() % 10;
				weight = 75 + rand() % 155;
				cars.push_back(Car(prise,weight));
			}
			Show(cars);
			for (int i{ 0 }; i < cars.size(); i++) {
				cars[i].TotalPrise();
			}
			break;
		}
		case '4': {
			break;
		}
		case EXIT: {
			std::cout << "\nExiting..";
			break;
		}
		default: {
			std::cout << "\nYou are missed";
			break;
		}
		}
	} while (choice != EXIT);
}