#include "Exeptions.h"
inline double Func(int a, int b) {
	return a / b;
}
Fraction::Fraction(int a, int& b) {
	try {
		if (b == 0)
			throw std:: runtime_error("\nYou can't divide on a zero");
	}
	catch (std:: runtime_error& a) {
		std:: cout << a.what();
		b = 1;
	}
}
template<typename T>
Queue<T>::Queue() {
	this->left = nullptr;
	this->right = nullptr;
	this->data = NULL;
}
template<typename T>
void Queue<T>::Push(Queue<T>*(&ptr) ,T& obj) {
	static Queue<T>* _left;
	try {
		if (ptr != nullptr) { //first time
			_left = this;
			ptr->Push(ptr->right, obj);
		}
		else if (ptr == nullptr) {
			this->size++;
			if (MAX_SIZE < size|| MAX_SIZE==this->size) {
				throw std::bad_alloc();
			}
			ptr = new Queue<T>;
			ptr->data = obj;
			ptr->right = nullptr;
			ptr->left = _left;
			ptr->size = ptr->left->size;
		}
	}
	catch (std::exception& exc) {
		std::cout << exc.what() << std::endl;
	}
	catch (...) {
		std::cout << "\nError occurs!";
	}
}
template<typename T>
void Queue<T>::Set(T& obj) {
	if (this != nullptr) {
		this->data = obj;
	}
	else {
		std::cout << "\nThis object is empty";
	}
}
template<typename T>
bool Queue<T>::Empty() {
	if (this->size == 0)
		return true;
	else
		return false;
}
template<typename T>
void Queue<T>::Pop() { 
	try {
		if (this == nullptr)
			throw std::bad_array_new_length);
		else {
				this->left->Delete();
				this->size--;
			
		}
	}
	catch (std:: exception& exp) {
		std:: cout << exp.what();
	}
}
template<typename T>
bool Queue<T>::Delete() {
	this->right = nullptr;
	this->left = nullptr;
	try {
		delete this;
		this = nullptr;
		return true;
	}
	catch (std::exception& exc) {
		std::cout<<exc.what();
		return false;
	}
}
//template<typename T>
//Queue<T>* Queue<T>::Begin() {
//	try {
//		if (this->Empty()) {
//			throw std::bad_array_new_length();
//		}
//		else
//			return this->left;
//
//	}
//	catch (std:: exception& exp) {
//		std:: cout << exp.what();
//		return nullptr;
//	}
//}
//template<typename T>
//Queue<T>* Queue<T>::End() { 
//	
//}
template <typename T>
void Queue<T>::Show() noexcept {
	if (this == nullptr) {
		return;
	}
	else {
		std::cout << this->data << " ";
		this->right->Show();
	}
}
template<typename T>
Queue<T>::~Queue() {
	try {
		if (this != nullptr) {
			delete this;
		}
	}
	catch (...) {

	}
}