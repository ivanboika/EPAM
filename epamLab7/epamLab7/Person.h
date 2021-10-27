#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <cassert>
#include <exception>
using namespace std::chrono;
#define STD std:: // just coz it's easier to use instead of std::
#define _GET STD getline(out, intermediate); // easier to use
enum KEY_WORDS {
	EXIT = 0,
};
class Person {
private:
	int day_of_birth;
	std::string name;
	std::string patronymic;
	std::string gender;
public:
	std::string surname;
	int month_of_birth;
	int year_of_birth;
	Person();
	Person(std::string , std::string , std::string);
	Person(std::string name, std::string surname, std::string patronymic, int day, int month, int year, std::string gender) : name(name),surname(surname),gender(gender), day_of_birth(day),month_of_birth(month),year_of_birth(year) {};
	friend void InTo(std::ofstream&, std::vector<Person>&);
	friend void OutOf(std::ifstream&, std::vector<Person>&);
	void SetData();
	std::string GetValidString(); // used to get string from user
	void GetValidString(std::string& obj); // used to get string from file
	void GetValidDate(STD string&); // used to get string from file 
	void GetValidDate(); // used to get date from user
	void Show()const;
	void SetN(STD string&); // set name
	void SetS(STD string&); // set surname
	void SetP(STD string&); // set patro
	void SetG(STD string&); // set gender
	friend void SortSurname(STD vector<Person>&);
	Person& operator=(const Person&);
};
class Fraction {
private:
	int dividend;
	int divider;
public:
	Fraction(int, int);
};
void Menu(int&,STD vector<Person>&);
double Func(int, int);
