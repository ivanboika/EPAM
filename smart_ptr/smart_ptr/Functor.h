#pragma once
#include"Student.h"
class Functor {
public:
	bool operator()(Student& obj1, Student& obj2, int field = 3) noexcept {
		switch (field) {
		case name: {
			return obj1.name_ < obj2.name_;
			break;
		}
		case group: {
			return obj1.group_ < obj2.group_;
			break;
		}
		case age: {
			return obj1.age_ < obj2.age_;
			break;
		}
		case year: {
			return obj1.year_of_education_ < obj2.year_of_education_;
			break;
		}
		default: {
			return false;
			break;
		}
		}
	}
	bool operator()(std::unique_ptr<Student>& obj1, std::unique_ptr<Student>& obj2, int field=3) noexcept {
		switch (field) {
		case name: {
			return obj1.get()->name_ < obj2.get()->name_;
			break;
		}
		case group: {
			return obj1.get()->group_ < obj2.get()->group_;
			break;
		}
		case age: {
			return obj1.get()->age_ < obj2.get()->age_;
			break;
		}
		case year: {
			return obj1.get()->year_of_education_ < obj2.get()->year_of_education_;
			break;
		}
		default: {
			return false;
			break;
		}
		}
	}
};