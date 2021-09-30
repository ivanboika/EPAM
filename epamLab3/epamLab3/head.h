#pragma once
#include<iostream>
#include<conio.h>
#include<ctime>
class Vector {
private:
	int size;
	int* array_;
public:
	Vector(int size = 1) : size(size) {
		if ((size > 64)) {
			std::cout << "Size of vector can not be more than 64" << std::endl;
			this->size = 64;
			this->array_ = new int[size];
		}
		else {
			int* temp = new int[size];
			delete this->array_;
			this->array_ = nullptr;
			this->array_ = temp;

		}
	}
	~Vector() {
		std::cout << "Vector is deleted!\n";
	}
	Vector operator[](int i) {
		return this->array_[i];
	}
	
	void Show() {
		for (int i{ 0 }; i < this->size; i++) {
			std::cout << this->array_[i];
		}
	}
	void SetRandomNumbers() {
		for (int i{ 0 }; i < this->size; i++)
			(*this)[i] = 1 + rand() % 64;
	}
	void Push_back(const int &number) {

	}
	int Length() {
		return this->size;
	}
};