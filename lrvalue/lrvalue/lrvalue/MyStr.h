#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
class MyStr {
private:
	std::vector<char>* str_;
public:
	MyStr();
	MyStr(std::vector<char>) = delete;
	MyStr(MyStr&); 
	explicit MyStr(MyStr&&)noexcept;
	explicit MyStr(const std::string&);
	~MyStr();
	void Show() noexcept;
	//MyStr& operator=(MyStr&);
	MyStr& operator=( MyStr&&) noexcept;
	std::vector<char>*& Get();
};
class TextView {
private:
	MyStr* str_;
public:
	explicit TextView(MyStr&&)noexcept;
	explicit TextView(TextView&& obj) noexcept;
	void Show();
	~TextView();
};
template <class C, typename V>
C Find_if(C first, C last, V v) {
	for (; first != last; ++first) {
		if (*first == v)
			return first;
	}
	return last;
}
template <class C, typename V>
std::vector<C> find_all(C it1, C it2, V v) {
	std::vector<C>temp;
	for (C it = it1; it != it2; ++it) {
		if (*it == v)
			temp.push_back(it);
	}
	return temp;
}