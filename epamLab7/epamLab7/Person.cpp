#include "Person.h"
Person::Person() {
	this->day_of_birth = 1;
	this->gender = "N/A";
	this->month_of_birth = 1;
	this->name = "N/A";
	this->patronymic = "N/A";
	this->surname = "N/A";
	this->year_of_birth = 1970;
}
Person::Person(std::string name, std::string surname, std::string patronymic) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->day_of_birth = 1;
	this->month_of_birth = 1;
	this->year_of_birth = 1970;
}
std::string Person::GetValidString() { 
	char temporary{ 'y' }; 
	std::string intermediate;
	int i{ 0 };
	while (temporary != 9) {
		temporary =_getche();
		if ((temporary > 64 && temporary < 123) || temporary == 9) { //user can use only words and tab for exit
			intermediate.push_back(temporary);
		}
		else {
			std::cout << "\nEnter only alphabet symbols or use tab for exit" << std::endl;
			std::cout << intermediate;
		}
		i++;
	}
	intermediate.pop_back();
	return intermediate;
}
void Person::Show() {
	STD cout << "\nThe name is " << this->name << " " << this->surname << " " << this->patronymic << STD endl;
	STD cout << "Gender is " << this->gender << ". Date of birth is " << this->day_of_birth << "." << this->month_of_birth << "." << this->year_of_birth << STD endl;
}
void Person::GetValidDate() {
	char temporary{ 'y' };
	std::string intermediate;
	int counter{ 0 };
	while (temporary != 9 ) { // try to use std::cin.clear() to make /n useful as end of string (getline string)
		temporary = _getche();
		if ((temporary > 47 && temporary < 58) || temporary == 9 || temporary==46) { // user can use only nums and '.' and tab for exit
			if (temporary == 46 || temporary==9) { // counter for date fields
				switch (counter){
				case 0: {
					this->day_of_birth = stoi(intermediate);
					break;
				}
				case 1: {
					this->month_of_birth = stoi(intermediate);
					break;
				}
				case 2: {
					this->year_of_birth = stoi(intermediate);
				}
				default:
					break;
				} 
				intermediate.clear();
				counter++;
			}
			else
			intermediate.push_back(temporary);
		}
		else {
			std::cout << "\nEnter only numbers and point or use tab for exit. Write date again" << std::endl;
			intermediate.clear();
		}
	}
}
void Person::SetData() {
	std::cout << "\nEnter your name (tap Tab for exit): ";
	this->name = GetValidString();
	std::cout << "\nEnter your surname (tap Tab for exit): ";
	this->surname = GetValidString();
	std::cout << "\nEnter your patronymic (tap Tab for exit): ";
	this->patronymic = GetValidString();
	std::cout << "\nEnter your gender (tap Tab for exit): ";
	this->gender = GetValidString();
	std::cout << "\nEnter your date of birth (DD.MM.YYYY) (tap Tab for exit): ";
	GetValidDate();
}
void InTo(std::ofstream& in,std::vector<Person>&obj) {
	unsigned counter{ 0 };
	unsigned size = obj.size();
	while (counter < size) {
		in << "¹" << counter << STD endl;
		in << obj[counter].name << STD endl;
		in << obj[counter].surname << STD endl;
		in << obj[counter].patronymic << STD endl;
		in << obj[counter].gender << STD endl;
		in << obj[counter].day_of_birth << "." << obj[counter].month_of_birth << "." << obj[counter].year_of_birth<<STD endl;
		counter++;
	}
}
void OutOf(std::ifstream& out, std::vector<Person>& obj) {

}