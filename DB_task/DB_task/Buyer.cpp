#include "Buyer.h"
#include"libs.h"
Buyer::Buyer() {
	std::cout << "\nDefault constructor happened";
	this->boughts = NULL;
	this->email = "";
	this->summ_boughts = NULL;
	this->name_ = "";
}
Buyer::Buyer(std::string&& name, std::string&& email, int boughts, double total_prise) {
	this->email = std::move(email);
	this->name_ = std::move(name);
	this->summ_boughts = std::move(total_prise);
	this->boughts = std::move(boughts);
	std::cout << "\nConstructor with parameters";
}
Buyer::Buyer(Buyer&&obj) noexcept{
	*this = std::move(obj);
	std::cout << "\nMove constructor happened: " << &obj;
	obj.~Buyer();
}
Buyer& Buyer::operator=(Buyer&obj) {
	this->name_ = obj.name_;
	this->email= obj.email;
	this->boughts= obj.boughts;
	this->summ_boughts= obj.summ_boughts;
	std::cout << "\nCopy logic";
	return *this;
}
Buyer& Buyer::operator=(Buyer&&obj) noexcept{
	std::swap(this->name_, obj.name_);
	std::swap(this->email, obj.email);
	std::swap(this->boughts, obj.boughts);
	std::swap(this->summ_boughts, obj.summ_boughts);
	obj.~Buyer();
	std::cout << "\nMove logic. Memory of rvalue reference: " << &obj;
	return *this;
}
void Buyer::Show() const{
	std::cout << "\nName: " << this->name_;
	std::cout << "\nEmail: " << this->email;
	std::cout << "\nBoughts: " << this->boughts;
	std::cout << "\nTotal spend: " << this->summ_boughts;
}
void Buyer::Generator() {
	// part 1 - email
	std::string temp{ "" };
	int size{ 0 };
	size = 1 + rand() % 10;
	for (int i{ 0 }; i < size; i++) {
		temp.push_back(64 + rand() % 57);
	}
	temp.push_back('@');
	temp += this->GetMail();
	this->email = temp;
	// part 2 - name
	size = 1 + rand() % 10;
	temp = "";
	for (int i{ 0 }; i < size; i++) {
		temp.push_back(65 + rand() % 57);
	}
	this->name_ = temp;
	// part 3 - boughts
	this->boughts= 1 + rand() % 1000; 
    // part 4 - total money spent
	this->summ_boughts = (boughts * (1 + rand() % 50)) / (1 + rand() % 13);
}
Buyer::~Buyer() {
	this->boughts = 0;
	this->email = "";
	this->name_ = "";
	this->summ_boughts = 0;
	std::cout << "\ndestructor happened";
}
std::string Buyer::GetMail () const{
	const std::vector<std::string>mails = { "gmail.com","mail.ru","yandex.ru","amogus.sus","rambler.ru"};
	return mails[1 + rand() % 5 - 1];
}
int Buyer::GetBoughts() const{
	return this->boughts;
}