#pragma once
#include "H:\empty\DB_task\DB_task\libs.h"
#include "Currency.h"
#include "BLR.h"
#include "EUR.h"
#include "RUB.h"
#include "USD.h"
#include"tempClass.h"
struct Types {
	const std::vector<std::string> BLR_type{ "BLR","blr","BYR","byr" };
	const std::vector<std::string> EUR_type{ "EUR","eur","euro","EURO" };
	const std::vector<std::string> USD_type{ "$","usd","USD" };
	const std::vector<std::string> RUB_type{ "RUB","rub" };
};
int GetType(std::string, Types* a=new Types);
class Funcs abstract{
public:
	virtual void Show() = 0;
	inline friend void GetAll(std::string from_user, std::vector<Currency*>& values, std::vector<char>& signs);
};
inline void GetAll(std::string from_user, std::vector<Currency*>& values, std::vector<char>& signs) {
	std::string temp{ "" };
	std::string type{ "" };
	for (int i{ 0 }; i < from_user.size(); i++) { //read and translate what user typed 
		if ((from_user[i] >= '0' && from_user[i] <= '9') || from_user[i] == '.') {
			temp.push_back(from_user[i]);
		}
		else { // we have value of currency at that point of time, so wee need to understand type of this currency
			if (from_user[i] >= 'A' && from_user[i] <= 'z') { // 
				type.push_back(from_user[i]);
				// if this is last word
				if (i == from_user.size() - 1) {
					int _type = GetType(type);
					if (_type == 1) {
						values.push_back(new RUB(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 2) {
						values.push_back(new USD(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 3) {
						values.push_back(new EUR(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 4) {
						values.push_back(new BLR(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else {
						temp.clear();
						type.clear();
						throw std::bad_typeid();
					}
				}
			}
			else {
				if (from_user[i] == '+' || from_user[i] == '-') { // we have the type, so gonna describe what programm needs to do
					signs.push_back(from_user[i]);
					int _type = GetType(type);
					if (_type == 1) {
						values.push_back(new RUB(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 2) {
						values.push_back(new USD(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 3) {
						values.push_back(new EUR(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else if (_type == 4) {
						values.push_back(new BLR(std::stof(temp)));
						temp.clear();
						type.clear();
					}
					else {
						temp.clear();
						type.clear();
						throw std::bad_typeid();
					}
				}
				else {
					std::cout << "\nSomething went wrong";
					throw std::bad_typeid();
				}
			}
		}
	}
}
int GetType(std::string type, Types* a ) {
	if (std::find(a->BLR_type.begin(), a->BLR_type.end(), type) != a->BLR_type.end()) {
		delete a;
		return 4;
	}
	if (std::find(a->RUB_type.begin(), a->RUB_type.end(), type) != a->RUB_type.end()) {
		delete a;
		return 1;
	}
	if (std::find(a->USD_type.begin(), a->USD_type.end(), type) != a->USD_type.end()) {
		delete a;
		return 2;
	}
	if (std::find(a->EUR_type.begin(), a->EUR_type.end(), type) != a->EUR_type.end()) {
		delete a;
		return 3;
	}
}