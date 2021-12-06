#pragma once
#include"Student.h"
class Functor {
public:
	bool operator()(const Student& obj1,const  Student& obj2, int field=3) noexcept{
		switch (field) {
		case name: {
			return obj1.name_ > obj2.name_;
			break;
		}
		case group: {
			return obj1.group_ > obj2.group_;
			break;
		}
		case age: {
			return obj1.age_ > obj2.age_;
			break;
		}
		case year: {
			return obj1.year_of_education_ > obj2.year_of_education_;
			break;
		}
		default: {
			return false;
			break;
		}
		}
	}
};