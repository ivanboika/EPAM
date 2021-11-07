#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
#include <exception>
template <typename T>
class Queue {
private:
	Queue<T>* left;
	const int MAX_SIZE = 5;
	T data;
	int size;
public:
	Queue<T>* right;
	//Queue<T>* iterator;
	inline Queue();
	inline void Push(Queue<T>* (&obj),T&);
	inline void Pop();
	inline void Show() noexcept;
	Queue<T>* Begin();
	Queue<T>* End();
	void Set(T&);
	bool Delete();
	inline bool Empty();
	inline ~Queue() noexcept;
};
class Fraction {
private:
	int dividend;
	int divider;
public:
	inline Fraction(int, int&);
};
