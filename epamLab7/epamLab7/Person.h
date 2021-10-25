#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <chrono>
using namespace std::chrono;
#define STD std:: // just coz it's easier to use instead of std::
class Person {
private:
	int day_of_birth;
	int month_of_birth;
	int year_of_birth;
	std::string name;
	std::string surname;
	std::string patronymic;
	std::string gender;
public:
	Person();
	Person(std::string , std::string , std::string);
	Person(std::string name, std::string surname, std::string patronymic, int day, int month, int year, std::string gender) : name(name),surname(surname),gender(gender), day_of_birth(day),month_of_birth(month),year_of_birth(year) {};
	friend void InTo(std::ofstream&, std::vector<Person>&);
	friend void OutOf(std::ifstream&, std::vector<Person>&);
	void SetData();
	std::string GetValidString();
	void GetValidDate();
	void Show();
};

