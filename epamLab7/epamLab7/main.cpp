#include "Person.h"
int main() {
	Person a;
	a.SetData();
	a.Show();
	STD ofstream file("Test1.txt");
	STD vector<Person> persons(5);
	persons.push_back(a);
	InTo(file, persons);
}