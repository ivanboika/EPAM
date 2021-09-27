#include "Header.h"
String::String() {
	this->string_.resize(0);
}
String::String(std::vector<char>& obj) {
	this->string_ = obj;
}
void String::SetString(char*str,int size) {
	for (int i{ 0 }; i < size; i++) {
		this->string_[i] = str[i];
	}
}
void String::SetString() {
	std::cout << "¬ведите вашу строку: ";

}