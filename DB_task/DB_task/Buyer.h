#pragma once
#include <iostream>
class Buyer {
private:
	std::string name_;
	std::string email;
	int boughts;
	double summ_boughts;
public:
	Buyer();
	explicit Buyer(std::string&&, std::string&&, int, double);
	explicit Buyer(Buyer&&)noexcept;
	Buyer(const Buyer&) = default;
	Buyer& operator=(Buyer&);
	Buyer& operator=(Buyer&&)noexcept;
	void Show() const;
	void Generator();
	~Buyer();
	std::string GetMail() const;
	int GetBoughts() const;
};

