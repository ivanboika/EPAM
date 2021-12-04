#include<iostream>
#include<string>
struct Student {
	int group = 19;
	bool a{ true };
	double b = 0.5;
};
int main() {
	setlocale(LC_ALL, "rus");
	Student students[30];
	int size;
	std::cout << "Enter the size: "; std::cin >> size;
	Student* studes = new Student[size];
	std::cout << "Taken memory is :" << sizeof(students) << std::endl;
	for (int i{ 0 }; i < 30; i++) {
		std::cout << (students + i) << " ";
	}
	std::cout << std::endl;
	auto ptr = studes;
	studes++;
	std::cout << studes  - ptr;
	std::cout << std::endl;
	std::cout <<  " " << &(students->group);
	return 0;
}