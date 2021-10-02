#include"head.h"
int main() {
	srand(time(NULL) * 1000);
	Vector first(10);
	first.SetRandomNumbers();
	Vector second(first);
	second.Show();
	second.Sort();
	second.Show();
	second.MinNum();
	second.MaxNum();
	std::cout << "\nAverage of nums is : " << second.AverageNum() << std::endl;
	second.Task();
	second.Show();
	//std::cout << first[6];
	return 0;
}