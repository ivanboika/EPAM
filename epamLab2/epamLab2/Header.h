#pragma once
#include<iostream>
#include <vector>
class String {
private:
	std::vector<char>string_;
public:
	String();
	String(std::vector<char>&);
	void SetString(char*, int);
	void SetString();
	String GetString(String&);
	int GetLength(String&);
};