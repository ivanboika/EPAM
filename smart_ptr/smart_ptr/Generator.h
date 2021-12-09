#pragma once
#include"Student.h"
class Generator { // >65 <90
public:
	void operator()(Student& obj) {
		obj.age_ = 18 + rand() % 5;
		obj.year_of_education_ = 1 + rand() % 4;
		int counter{ 1 + rand() % 7 };
		obj.name_ = "";
		obj.group_ = "";
		for (int i{ 0 }; i < counter; ++i) { //postfix and prefix form of increment
			obj.name_.push_back(65 + rand() % 25);
			if (counter < 5)
				obj.group_.push_back(65 + rand() % 25);
		}
	}
};