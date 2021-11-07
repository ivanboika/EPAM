#include "Person.h"
int main() {
	STD vector<Person> persons(1);
	int choice{ 1 };
	STD ifstream out("Test1.txt");
	if (out.is_open()) {
		OutOf(out, persons);
	}
	else {
		STD cout << "File isn't open";
	}
	while (choice != EXIT) {
		STD cout << "2-Show data\n3-Sort by surname\n4-Show persons which were born in chosen month\n5-Show surname of oldest male\n6-Show all surnames which start from chosen symbol\n0-Exit\nChoice: ";
		STD cin >> choice;
		Menu(choice, persons);
	}
}