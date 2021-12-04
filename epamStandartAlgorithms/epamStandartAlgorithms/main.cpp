#include<iostream>
#include<chrono>
#include<ctime>
#include<vector>
#include<algorithm>
#define TYPE int
using namespace std::chrono;
bool find(std::vector<TYPE>&, TYPE, int, int);
void sort(std::vector<TYPE>&);
void choice_sort(std::vector<TYPE>&);
int main() {
	srand(time(NULL) * 1000);
	std::vector<TYPE>nums(1000);
	for (int i{ 0 }; i < nums.size(); i++) {
		nums[i] = (1 + rand() % 100 - 50);
	}
	//вставки
	std::vector<TYPE>nums_1(nums);
	auto start = steady_clock::now();
	sort(nums);
	auto end = steady_clock::now();
	auto elapsed = duration_cast<microseconds>(end - start);
	std::cout << elapsed.count();
	// выбором
	auto start_1 = steady_clock::now();
	choice_sort(nums_1);
	auto end_1 = steady_clock::now();
	auto elapsed_1 = duration_cast<microseconds>(end_1 - start_1);
	std::cout << std::endl << elapsed_1.count();
	////их
	auto start_3 = steady_clock::now();
	std::sort(nums.begin(), nums.end());
	auto end_3 = steady_clock::now();
	auto elapsed_3 = duration_cast<microseconds>(end_3 - start_3);
	std::cout << std::endl << elapsed_3.count();
	//их поиск
	auto start_5 = steady_clock::now();
	std::find(nums.begin(), nums.end(), 5);
	auto end_5 = steady_clock::now();
	auto elapsed_5 = duration_cast<microseconds>(end_5 - start_5);
	std::cout << std::endl << elapsed_5.count();
	//мой поиск
	auto start_2 = steady_clock::now();
	find(nums, 5, 0, nums.size()); 
	auto end_2 = steady_clock::now();
	auto elapsed_2 = duration_cast<microseconds>(end_2 - start_2);
	std::cout << std::endl << elapsed_2.count();
	return 0;
}
void choice_sort(std::vector<TYPE>& obj) {
	TYPE lowest{ 0 }, biggest{ 0 };
	int size = obj.size();
	for (int i{ 0 }; i < size; i++) {
		for (int j{ size - 1 }; j > i; j--) {
			if (lowest > obj[j])
				lowest = obj[j];
			if (biggest < obj[j])
				biggest = obj[j];
		}
		std::swap(lowest, obj[i]);
		std::swap(biggest, obj[size - 1 - i]);
	}
}
void sort(std::vector<TYPE>&obj) {
	for (int i{ 0 }; i < obj.size(); i++) {
		for (int j{ i }; j > 0 && obj[j] > obj[j - 1]; j--) {
			std::swap(obj[j], obj[j - 1]);
		}
	}
}
bool find(std::vector<TYPE>&obj,TYPE what,int start,int end) {
	if (obj[(start+end)/2] == what) {
		return true;
	}
	else {
		if (what > obj[(start + end) / 2]) {
			find(obj, what, ((start + end) / 2), end);
		}
		else {
			find(obj, what, start, ((start + end) / 2) );
		}
	}
}