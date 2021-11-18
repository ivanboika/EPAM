#include "Exeptions.h"
template<typename T>
Queue<T>::Queue() {
	this->left = nullptr;
	this->right = nullptr;
	this->iterator = nullptr;
	this->data = NULL;
	this->size = 0;
	this->first_time = true;
}
template <>
Queue<AviaTicket>::Queue() {
	this->left = nullptr;
	this->right = nullptr;
	this->iterator = nullptr;
	this->data.date = "N/A";
	this->data.end = "N/A";
	this->data.id = NULL;
	this->data.name = "N/A";
	this->size = 0;
	this->first_time = true;
}
template<typename T>
void Queue<T>::Push(Queue<T>* (&ptr), T& obj) {
	static Queue<T>* _left;
	try {
		if (ptr != nullptr) { //first time
			_left = ptr;
			ptr->Push(ptr->right, obj);
		}
		else if (ptr == nullptr) {
			if ((this->size > MAX_SIZE)) {
				throw std::out_of_range::exception("Out of range");
			}
			ptr = new Queue<T>;
			ptr->first_time = _left->first_time;
			ptr->size = _left->size;
			ptr->data = obj;
			ptr->right = nullptr;
			ptr->left = _left;
		}
	}
	catch (std::exception& exc) {
		this->size--;
		std::cout << exc.what() << std::endl;
	}
	catch (...) {
		std::cout << "\nError occurs!";
	}
}
template<typename T>
void Queue<T>::Set(T& obj) { // push for the first time
	if (this != nullptr) {
		this->data = obj;
		this->size++;
		this->first_time = false;
	}
	else {
		std::cout << "\nThis object is empty";
	}
}
template<typename T>
bool Queue<T>::Empty() { // check not for size, but for dinamic memory, which can be taken
	if (this==nullptr ) 
		return true;
	else if (this->data == NULL) {
		return true;
	}
	else
		return false;
}
template<>
bool Queue<AviaTicket>::Empty() {
	if (this == nullptr)
		return true;
	else if (this->data.id == NULL) {
		return true;
	}
	else
		return false;
}
template<typename T>
void Queue<T>::LeftNullptr() {
	this->left = nullptr;
}
template<typename T>
Queue<T>* Queue<T>::Pop() {
	if (this->Empty() ) {
		std::cout << "\nQueue is empty\n";
		return this;
	}
	try {
		if (this->left == nullptr) { 
				Queue<T>* temporary;
				if (this->right == nullptr && this->left==nullptr) // if we have one element
			    {
					/*delete this;*/
					return new Queue<T>;
				}
				temporary = this->right;
				temporary->size--;
				temporary->data = this->right->data;
				temporary->left = nullptr;
				this->Delete();
				return temporary;
		}
		else {
			this->left->Pop();
		}
	}
	catch (std:: exception& exp) {
		std:: cout << exp.what();
	}
}
template<typename T>
bool Queue<T>::Delete() {
	try {
		delete this;
		return true;
	}
	catch (std::exception& exc) {
		std::cout<<exc.what();
		return false;
	}
}
template <>
int Queue<AviaTicket>::Find(std::string& _date,int& _id) {
	static unsigned int count{ 0 };
	if (!this->Empty()) {
		if (this->data.date == _date && this->data.id == _id) {
			return count;
		}
		else
			this->right->Find(_date, _id);
	}
	else {
		std::cout << "\nPositions ended";
	}
}
template<typename T>
int& Queue<T>::Size() {
	return this->size;
}
template<>
Queue<AviaTicket>* Queue<AviaTicket>::Pop(int pos) {
	if (!this->Empty()) {
		if (pos != 0)
			this->right->Pop(pos - 1); // swap and pop
	}
	else {
		std::cout << "\nQueue is empty!";
		return nullptr;
	}
	if (pos == 0) { // we went to the pos
		if (this->left == nullptr) {
			return this->Pop();
		}
		Queue<AviaTicket>* temp{ nullptr };
		if (this->left != nullptr) {
			this->left->right = this->right;
			temp = this->right;
		}
		else
			this->left->right = nullptr;
		if (this->right != nullptr) //don't need to reference from empty pos
			this->right->left = this->left;
		/*else*/
			/*this->right->left = nullptr;*/
		delete this;
		this->data.id = 0;
		return temp;
	}
}
template<>
Queue<AviaTicket>* Queue<AviaTicket>::NewPop() {
	unsigned int pos{ 0 };
	if (this->Empty()) {
		std::cout << "\nQueue is empty!";
		return new Queue<AviaTicket>;
	}
	std::cout << "\nEnter the deleting pos: "; std::cin >> pos;
	Queue<AviaTicket>* temp = this->Pop(pos);
	return temp;
}

template <typename T>
Queue<T>* Queue<T>::Move(int& index) {
	if (this!=nullptr) {
		if (index == 0)
			return this;
		else
			this->right->Move(--index);
	}
	else {
		return nullptr;
	}
}
template <typename T>
void Queue<T>::Show() noexcept {
	if (this == nullptr) {
		std::cout << std::endl;
		return;
	}
	else {
		std::cout << this->data << " ";
		this->right->Show();
	}
}
template<>
void Queue<AviaTicket>::Show() noexcept{
	if (this->Empty()) {
		std::cout << std::endl;
	}
	else {
		this->left->Show();
		std::cout << this->data.id << " " << this->data.name << " " << this->data.date << " " << this->data.end << std::endl;
		this->right->Show();
	}
}
template<typename T>
Queue<T>* Queue<T>::Begin() {
	if (this->left != nullptr) { // if smth exist to the left
		this->left->Begin();
	}
	else
		return this->right; 
}
template<typename T>
const T& Queue<T>::Get() { return this->data; }
template<typename T>
Queue<T>* Queue<T>::End() {
	if (this->right != nullptr) { // if smth exist to the right
		this->right->End();
	}
	else
		return this;
}
template<>
Queue<AviaTicket>::~Queue() {
}
template<>
void Queue<AviaTicket>::Set(AviaTicket& obj) { // visual wants it
	if (this != nullptr) {
		this->data.id = obj.id;
		this->data.date = obj.date;
		this->data.end = obj.end;
		this->data.name = obj.name;
		this->size++;
		this->first_time = false;
	}
	else {
		std::cout << "\nThis object is empty";
	}
}
template<>
void Queue<AviaTicket>::LeftNullptr() {
	this->left = nullptr;
}
template<>
void Queue<AviaTicket>::Push(Queue<AviaTicket>* (&ptr), AviaTicket& obj) {
	static Queue<AviaTicket>* _left;
	try {
		if (ptr != nullptr) { //first time
			_left = ptr;
			ptr->Push(ptr->right, obj);
		}
		else if (ptr == nullptr) {
			if ((this->size > MAX_SIZE)) {
				throw std::out_of_range::exception("Out of range");
			}
			ptr = new Queue<AviaTicket>;
			ptr->first_time = _left->first_time;
			ptr->size = _left->size;
			this->data.id = obj.id;
			this->data.date = obj.date;
			this->data.end = obj.end;
			this->data.name = obj.name;
			ptr->right = nullptr;
			ptr->left = _left;
		}
	}
	catch (std::exception& exc) {
		this->size--;
		std::cout << exc.what() << std::endl;
	}
	catch (...) {
		std::cout << "\nError occurs!";
	}
}