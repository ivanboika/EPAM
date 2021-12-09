#include "Student.h"
Student::Student(std::string name /*= "N/A"*/, std::string group /*= "N/A"*/, int age /*= 0*/, int year /*= 0*/)noexcept : name_(name), group_(group), age_(age), year_of_education_(year) { };
void Student::ShowData() const noexcept{ // shows data abt person
	std::cout << "\nPerson's name is " << this->name_;
	std::cout << "\nGroup is " << this->group_; std::cout << "\nAge is " << this->age_; std::cout << "\nYear of education is " << this->year_of_education_ << std::endl;
}