#pragma once
#include "D:\git\new_epam\DB_task\DB_task\libs.h"
class Student {
private:
	std::string name_;
	std::string group_;
	int age_;
	int year_of_education_;
public:
	Student(std::string, std::string, int, int);
	explicit Student(const Student&) = default;
	explicit Student(Student&&) = default;
	Student& operator=(const Student&) = default;
	Student& operator=(Student&&) = default;
	~Student() = default;
	void ShowData() const;
};