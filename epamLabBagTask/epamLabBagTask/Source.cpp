#include"Bag.h"
#include<chrono>
using namespace std::chrono;
int main() {
	srand(time(NULL) * 1000);
	std::vector<Bag>bags;
	int size{ 0 };
	std::cout << "Enter the size of the vector: "; std::cin >> size;
	assert(!(size < 0));
	bags.resize(size);
	assign(bags);
	auto start = steady_clock::now(); // at this moment of time
	std::sort(bags.begin(), bags.end(), [](const Bag& a, const Bag& b) {return a.getRatio() < b.getRatio(); });
	auto end = steady_clock::now(); // to this moment of time
	duration<double> elapsed = (end - start); // second example, less code
	//duration<double> first = start.time_since_epoch(); // translating into seconds // first example, more code
	//duration<double> second = end.time_since_epoch(); // translating into seconds // first example, more code
	//both examples are working 
	std::cout << "\nElapsed time is " << elapsed.count() /*second.count()-first.count()*/ << std::endl;
	show(bags);
	//0.0001909 s - if i use method getRatio() and 50 objects
	//0.0001299 s - if i make raion field public and use this field directly with 50 objects
	std::vector<Bag>W;
	double total_weight{ 0 };
	std::cout << "Enter the total weight of the vector: "; std::cin >> total_weight;
	assert(!(total_weight < 0));
	double temporary{ 0 }; int counter{ 0 };
	while (temporary < total_weight) {
		W.push_back(bags[counter]); // push_back while capacity(weight) of W isn't full
		counter++;
		temporary += bags[counter].getWeight();
	};
	show(W);
	return 0;
}