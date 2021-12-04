#include"Array.cpp"
int main() {
	setlocale(0, "rus");
	srand(time(NULL) * 1000);
	Array<int> first(5, 5);
	first.ShowArray();
	Task(first);
	first.ShowArray();
	return 0;
}