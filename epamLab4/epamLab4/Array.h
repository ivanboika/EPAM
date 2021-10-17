#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
template<typename type>
class Array{
private:
	type** pfirst;
	type value;
	int fsize;
	int ssize;
public:
	Array(int fsize = 1, int ssize = 1, type value = 0); 
	Array(Array&);
	~Array();
	void ShowArray();
	int* operator[](int);
	void SetRandomValues();
	friend void Task(Array<type>& obj) {
		obj.SetRandomValues();
		bool isstringpos{ true };
		type result{ 0 };
		for (int i{ 0 }; i < obj.fsize; i++) {
			for (int j{ 0 }; j < obj.ssize; j++) {
				if (obj[i][j] <= 0) {
					j = obj.ssize;
					isstringpos = false;
				}
				else {
					continue;
				}	
			}
			if (isstringpos == true) {
				for (int j{ 0 }; j < obj.ssize; j++) {
					result += obj[i][j];
				}
			}
			isstringpos = true;
		}
		std::cout  << std::endl << result<<std::endl;
	}
};