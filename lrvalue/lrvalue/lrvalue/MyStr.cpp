#include "MyStr.h"
MyStr::MyStr(const std::string& _str) {
	this->str_ = new std::vector<char>;
	for (int i{ 0 }; i < _str.size(); i++)
		this->str_->push_back(_str[i]);
	std::cout << "\nconst strng & constructor happened";
}
MyStr::~MyStr() {
	if (this->str_ !=nullptr) {
		delete this->str_;
		this->str_ = nullptr;
	}
	std::cout << "\ndestructor happened";
}
MyStr::MyStr(MyStr& obj) {
	if (!this->str_)
		this->str_ = new std::vector<char>;
	*this->str_ = *obj.str_;
	std::cout << "\ncopy constructor happened";
}
MyStr::MyStr(MyStr&& obj) noexcept {
	if (!this->str_)
		this->str_ = new std::vector<char>;
	*this->str_= std::move(*obj.str_);
	std::cout << "\nAssignment constructor: ";
	delete obj.str_;
	obj.str_ = nullptr;
	std::cout << obj.str_ << std::endl;
}
MyStr &MyStr::operator=(MyStr&& obj) noexcept{
	std::cout << "\nMove assignment happened ";
	*(this->str_) = /*std::move*/std::move(*(obj.str_));
	delete obj.str_;
	obj.str_ = nullptr;
	std::cout << std::endl << obj.str_ << std::endl;	
	return *this;
}
//MyStr& MyStr::operator=(MyStr& obj) noexcept {
//	std::cout << "\Copy assignment happened ";
//	this->str_ = obj.str_;
//	std::cout << std::endl << obj.str_ << std::endl;
//	return *this;
//}
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

	std::cout << "\nConstructor of 2th class (with move) ";
	std::cout << obj.str_ << std::endl;
}
TextView::~TextView() {
	if (this->str_) {
		delete this->str_;
		this->str_ = nullptr;
	}
	std::cout << "\n2th class destructor happened";
}
TextView::TextView(MyStr&& obj) noexcept{
	if (!this->str_) {
		this->str_ = new MyStr;
	}
	*(this->str_) = std::move(obj);
	delete obj.Get();
	obj.Get() = nullptr;
	std::cout << "\n2th class move assignment happened: " << obj.Get();
}
void TextView::Show() {
	this->str_->Show();
}