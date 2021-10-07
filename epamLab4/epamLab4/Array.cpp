#include "Array.h"
template<typename type>
Array<type>::Array(int fsize, int ssize, type value) : fsize(fsize), ssize(ssize), value(value) {
	this->pfirst = new int* [this->fsize];
	for (int i{ 0 }; i < this->fsize; i++) {
		pfirst[i] = new int[this->ssize];
	}
	for (int i{ 0 }; i < this->fsize; i++) {
		for (int j{ 0 }; j < this->ssize; j++) {
			(this->pfirst)[i][j] = this->value;
		}
	}
}
	template <typename type>
	Array<type>::Array(Array<type>&obj) {
		this->fsize = obj.fsize;
		this->ssize = obj.ssize;
		this->pfirst = new  type*[this->fsize];
		for (int i{ 0 }; i < this->fsize; i++) {
			this->pfirst[i] = new type[this->ssize];
		}
		for (int i{ 0 }; i < this->fsize; i++) {
			for (int j{ 0 }; j < this->ssize; j++) {
				this->pfirst[i][j] = obj.pfirst[i][j];
			}
		}
}
	template<typename type>
	Array<type>::~Array() {
		for (int i{ 0 }; i < this->fsize; i++) {
			delete[] this->pfirst[i];
		}
		delete[] this->pfirst;
		this->pfirst = nullptr;
		std::cout << "\nArray is deleted!";
	}
	template <typename type>
	void Array<type>::ShowArray() {
		for (int i{ 0 }; i < this->fsize; i++) {
			for (int j{ 0 }; j < this->ssize; j++) {
				std::cout << this->pfirst[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	template<typename type>
	int* Array<type>::operator[](int i) {
		return (this->pfirst[i]);
	}
	 template<typename type>
	 void Array<type>::SetRandomValues() {
		 for (int i{ 0 }; i < this->fsize; i++) {
			 for (int j{ 0 }; j < this->ssize; j++) {
				 this->pfirst[i][j] = /*static_cast<type>*/(-10 + rand() % 128);
			 }
		 }
	 }
	 template <typename type>
	 void Task(Array<type>& obj) {
		 obj.SetRandomValues();
		 bool isstringpos{ true };
		 type result{ 0 };
		 for (int i{ 0 }; i < obj.fsize; i++) {
			 for (int j{ 0 }; j < obj.ssize; j++) {
				 if (obj[i][j] <= 0) {
					 isstringpos = false;
				 }
				 else
					 continue;
			 }
			 if (isstringpos == true) {
				 for (int j{ 0 }; j < obj.ssize; j++) {
					 result += obj[i][j];
				 }
			 }
		 }
		 std::cout << std::endl << result << std::endl;
	 }