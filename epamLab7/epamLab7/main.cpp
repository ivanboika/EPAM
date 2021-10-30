#include "Person.h"
int main() {
	STD vector<Person> persons(5);
	int choice{ 1 };
	while (choice != EXIT) {
		STD cout << "1-Get data from the file\n2-Show data\n3-Sort by surname\n4-Show persons which were born in chosen month\n5-Show surname of oldest male\n6-Show all surnames which start from chosen symbol\n0-Exit\nChoice: ";
		STD cin >> choice;
		Menu(choice, persons);
	}
}