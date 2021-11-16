#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#include <exception>
struct AviaTicket {
	std::string end;
	std::string date;
	int id;
	std::string name;
};
template <typename T>
class Queue {
private:
	Queue<T>* left;
	Queue<T>* right;
	const int MAX_SIZE = 5;
	T data;
	int size;
public:
	bool first_time;
	void LeftNullptr();
	Queue<T>* iterator;
	inline Queue();
	inline void Push(Queue<T>* (&obj),T&);
	inline Queue<T>* Pop();
	inline Queue<T>* Pop(int);
	inline void Show() noexcept;
	Queue<T>* Begin();
	Queue<T>* End();
	void Set(T&);
	bool Delete();
	inline bool Empty();
	inline ~Queue() noexcept;
	const T& Get();
	inline int Find(std::string&, int&);
	Queue<T>* Move(int& index);
	int& Size();
	inline Queue<T>* NewPop();
};