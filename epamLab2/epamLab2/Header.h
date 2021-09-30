#pragma once
#include<iostream>
#include <vector>
#include<conio.h>
class String {
private:
	std::vector<char>string_;
public:
	String();
	String(std::vector<char>&);
	void SetString(char*, int);
	void SetString();
	void Show();
	int GetLength();
	void Task();
	~String();
};
String::String() {
	string_.resize(0);
}
String::String(std::vector<char>& obj): string_(obj){
}
int String::GetLength() {
	return this->string_.size();
}
void String::SetString(char* str, int size) {
	for (int i{ 0 }; i < size; i++) {
		string_[i] = str[i];
	}
}
void String::SetString() {
	std::cout << "Enter your string (use TAB to end): ";
	char letter{ 'y' };
	while (letter != 9) {
		letter = _getche();
		string_.push_back(letter);
		if (this->GetLength() > 64 ) {
			std::cout << "String is full!" << std::endl;
			break;
		}
	}
	string_.pop_back();
}
void String::Show() {
	std::cout << std::endl;
	for (int i{ 0 }; i < this->GetLength(); i++) {
		std::cout << this->string_[i];
	}
	std::cout << std::endl;
}
void String::Task() {
	std::vector<char>::iterator for_erase{ (*this).string_.begin() };
	unsigned int counter{ 0 };
	for (int i{ 0 }; i < this->GetLength(); i++) {
		if (this->string_[i] == 'c') {
			this->string_[i] = *for_erase;
			counter++;
		}
	}
	std::cout << "\nAmount of changed words is " << counter;
}
String::~String() {
	std::cout << "\nString is deleted!";
}
