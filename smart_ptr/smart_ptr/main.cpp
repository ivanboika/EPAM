#include "/empty/DB_task/DB_task/libs.h"
#include <list>
#include "Student.h"
#include"Generator.h"
#include"Functor.h"
#include <memory>
int main() {
	std::vector<std::unique_ptr<Student>>sort_it;
	Generator gen;
	unsigned size{0};
	std::cout << "Enter size of vector: ";	std::cin >> size;
	for (int i{ 0 }; i < size; i++) { // initialization
		sort_it.push_back(std::unique_ptr<Student>(new Student()));
		gen(*sort_it[i].get());
	}
	std::for_each(sort_it.begin(), sort_it.end(), [](std::unique_ptr<Student>& a) {a->ShowData(); });
	Functor func;
	unsigned field{ 0 };
	std::cout << "\nEnter field for sort(1-name,2-group,3-age,4-year): "; std::cin >> field;
	std::cin.clear();
	std::cout << "\nNOW SOMETHING SHOULD CHANGE\n";
	std::sort(sort_it.begin(), sort_it.end(), [=, &func](std::unique_ptr<Student>& obj1, std::unique_ptr<Student>& obj2) {return func(obj1, obj2, field); });
	std::for_each(sort_it.begin(), sort_it.end(), [](std::unique_ptr<Student>& a) {a->ShowData(); });
	for (int i{ 0 }; i < sort_it.size(); ++i) {
		sort_it[i].release();
	}
	sort_it.clear();
	std::cout << std::endl;
	return 0;
}