#include "Person.h"
int main() {
	//Person a;
	//a.SetData();
	//a.Show();
	//STD ofstream file("Test1.txt");
	STD vector<Person> persons(3);
	//persons.push_back(a);
	//InTo(file, persons);
	int choice{ 1 };
	while (choice != EXIT) {
		STD cout << "1-Get data from the file\n2-Show data\n3-Sort by surname\n4-Show persons which were born in chosen month\n5-Show surname of oldest male\n6-Show all surnames which start from chosen symbol\nChoice: ";
		STD cin >> choice;
		Menu(choice, persons);
	}
}