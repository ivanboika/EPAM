#pragma once
#include "/empty/DB_task/DB_task/libs.h"
enum FIELDS {
	name=1,
	group,
	age,
	year
};
class Generator;
class Functor;
class Student {
private:
	std::string name_;
	std::string group_;
	int age_;
	int year_of_education_;
public:
	friend class Functor;
	friend class Generator;
	Student(std::string, std::string, int, int)noexcept;
	explicit Student(const Student&) = default;
	explicit Student(Student&&) = default;
	Student& operator=(const Student&) = default;
	Student& operator=(Student&&) = default;
	~Student() = default;
	void ShowData() const noexcept;
};