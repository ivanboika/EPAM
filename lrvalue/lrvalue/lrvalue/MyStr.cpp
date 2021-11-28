#include "MyStr.h"
MyStr::MyStr(const std::string& _str) {
	this->str_ = new std::vector<char>;
	for (int i{ 0 }; i < _str.size(); i++)
		this->str_->push_back(_str[i]);
	std::cout << "\nconst strng & constructor happened";
}
MyStr::~MyStr() {
	if (this->str_) {
		delete this->str_;
		this->str_ = nullptr;
	}
	std::cout << "\ndestructor happened";
}
MyStr::MyStr(MyStr& obj) {
	this->str_ = obj.str_;
	std::cout << "\ncopy constructor happened";
}
MyStr::MyStr(MyStr&& obj) noexcept {
	std::swap((this->str_), (obj.str_));
	obj.~MyStr();
	std::cout << "\nAssignment constructor: ";
	std::cout << obj.str_ << std::endl;
}
MyStr &MyStr::operator=(MyStr&& obj) noexcept{
	std::cout << "\nMove assignment happened ";
	std::swap((this->str_), obj.str_); 
	/*obj.~MyStr();*/
	std::cout << std::endl << obj.str_ << std::endl;	
	return *this;
}
MyStr::MyStr() {
	this->str_ = new std::vector<char>;
	this->str_->resize(0);
}
void MyStr::Show() noexcept{
	for (int i{ 0 }; i < this->str_->size(); i++)
		std::cout << ((*this->str_)[i]);
	std::cout << std::endl;
}
std::vector<char>*& MyStr::Get() {
	return this->str_;
}
TextView::TextView( TextView&& obj) noexcept{
	if (!this->str_) {
		this->str_ = new MyStr;
	}
	/*this->str_ = std::move(obj.str_);*/
	std::swap(this->str_, obj.str_);
	/*obj.~TextView();*/
	std::cout << "\nConstructor of 2th class (with move) ";
	std::cout << &obj << std::endl;
}
TextView::~TextView() {
	this->str_->~MyStr();
	delete this->str_;
	this->str_ = nullptr;
	std::cout << "\n2th class destructor happened";
}
TextView::TextView(MyStr&& obj) noexcept{
	if (!this->str_) {
		this->str_ = new MyStr;
	}
	//*(this->str_) = std::move(obj);
	std::swap(this->str_->Get(), obj.Get());
	obj.~MyStr();
	std::cout << "\n2th class move assignment happened: " << obj.Get();
}
void TextView::Show() {
	this->str_->Show();
}