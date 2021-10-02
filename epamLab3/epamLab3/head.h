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
			for (int i{ 0 }; i < size; i++) {
				this->array_[i] = 0;
			}
		}
		else {
			if (size > 0) {
				array_ = new int[this->size];
				for (int i{ 0 }; i < this->size; i++)
					this->array_[i] = 0;
			}
			else {
				std::cout << "\nSize of vector can not be less than a zero";
				this->size = 1;
				this->array_ = new int[size];
				for (int i{ 0 }; i < size; i++) {
					this->array_[i] = 0;
				}
			}
		}
	}
	Vector(Vector& obj) {
		this->array_ = new int[obj.size];
		this->size = obj.size;
		this->Copy(obj);
	}
	~Vector() {
		delete[] array_;
		array_ = nullptr;
		std::cout << "\nVector is deleted!";
	}
	int& operator[](int i) {
		return (this->array_[i]);
	}
	Vector& Copy(Vector& obj) {
		if (this->size >= obj.size) {
			for (int i{ 0 }; i < obj.size; i++) {
				this->array_[i] = obj.array_[i];
			}
		}
		else {
			for (int i{ 0 }; i < this->size; i++) {
				this->array_[i] = obj.array_[i];
			}
		}
		return *this;
	}
	void Show() {
		for (int i{ 0 }; i < this->size; i++) {
			std::cout << (this->array_[i]) << " ";
		}
		std::cout << std::endl;
	}
	void SetRandomNumbers() {
		for (int i{ 0 }; i < this->size; i++)
			this->array_[i] = -64 + rand() % 128;
	}
	void Push_back(const int& number) {
		this->size++;
		int* temp = new int[size];
		temp[size - 1] = number;
		for (int i{ 0 }; i < size - 1; i++) {
			temp[i] = this->array_[i];
		}
		delete[]temp;
		temp = nullptr;
	}
	void Sort() {
		for (int i{ 1 }; i < this->size; i++) {
			for (int j = i; j > 0 && (this->array_[j] < this->array_[j - 1]); j--) {
				this->Swap(this->array_[j], this->array_[j - 1]);
			}
		}
	}
	void MinNum() {
		this->Sort();
		std::cout << "\nMin element is: " << (*this)[0];
	}
	void MaxNum() {
		this->Sort();
		std::cout << "\nMax element is: " << (*this)[this->size - 1];
	}
	double AverageNum() {
		double sum{ 0 };
		for (int i{ 0 }; i < this->size; i++) {
			sum += (*this)[i];
		}
		sum /= this->size;
		return sum;
	}
	void Swap(int& first, int& second) {
		int temp = first;
		first = second;
		second = temp;
	}
	int Length() {
		return this->size;
	}
	int GetpMinNum() {
		int temp;
		this->Sort();
		temp = (*this)[this->size / 2];
		if (temp < 0) {
			for (int i{ this->size / 2 }; i < this->size; i++) {
				if ((*this)[i] >= 0) {
					temp = (*this)[i];
					break;
				}
			}
		}
		else {
			for (int i{ this->size / 2 }; i > 0; i--) {
				if ((*this)[i] <= 0) {
					temp = (*this)[i + 1];
					break;
				}
			}
		}
		return temp;
	}
	void Task() {
		//20th
		int temp = this->GetpMinNum();
		for (int i{ 0 }; i < this->size; i += 2) {
			if (i > this->size) {
				break;
			}
			(*this)[i] = temp;
		}
	}
};