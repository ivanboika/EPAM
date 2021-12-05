#include "D:\git\new_epam\DB_task\DB_task\libs.h"
#include <list>
#include "Student.h"
int main() {
	std::list<Student> students(10, { "a","b",10,1 });
	//std::for_each(students.begin(), students.end(), [](const Student& obj) {obj.ShowData(); });
	std::vector<Student*>sort_it; 
	//sort_it.push_back(Student("Yo","HO-HO",19,2));
	//std::cout << sort_it.size() << " " << sort_it.capacity();

	return 0;
}