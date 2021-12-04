#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<iostream>
#include<ctime>
#include<algorithm>

class Bag {
private:
	double prise;
	double weight;
	
public:
	double ratio;
	Bag();
	Bag(int prise, int weight) {
		assert(!(prise < 0) || !(weight < 0));
		this->prise = prise;
		this->weight = weight;
		this->ratio = weight / prise;
	}
	Bag(const Bag&);
	inline void show() const;
	friend  void show(const std::vector<Bag>&) ;
	friend  void assign(std::vector<Bag>&);
	const double getRatio() const;
	Bag& operator=(const Bag&);
	double getWeight() const;
};