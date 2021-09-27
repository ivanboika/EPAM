#include <iostream>
#include<string>
using namespace std;
struct Student {
	string name;
	string surname;
	int scores[3];
};
void Show(Student*, int);
void Sort(Student* (&), int);
int BestScore(Student(&), int);
int main() {
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите размер массива(>5): "; cin >> size;
	while (size >5) {
		cout << "Введите размер массива(Больше 5): "; cin >> size;
	}
	Student* students = new Student[size];
	for (int i{ 0 }; i < size; i++) {
		cout << "Студент № " << i + 1 << endl;
		cout << "Введите имя студента: ";
		cin >> students[i].name;
		cout << "Введите фамилию студента: ";
		cin >> students[i].surname;
		cout << "Введите оценки студента: " << endl;
		for (int j{ 0 }; j < 3; j++) {
			cout << "Оценка " << j + 1 << ": ";
			cin >> students[i].scores[j];
		}
	}
	Sort(students, size);
	Show(students, size);
	delete[] students;
	students = nullptr;
	return 0;
}
void Show(Student* obj, int size) {
	for (int i{ 0 }; i < size; i++) {
		cout << "\nСтудент № " << i + 1 << endl;
		cout << "Имя студента: "; cout << obj[i].name << endl;
		cout << "Фамилия студента: "; cout << obj[i].surname << endl;
		cout << "Оценки студента: ";
		for (int j{ 0 }; j < 3; j++) {
			cout << "\nОценка " << j + 1 << ": ";
			cout << obj[i].scores[j];
		}
	}
}
int BestScore(Student(&obj), int size) {
	int result{ 0 };
	for (int i = { 0 }; i < 3; i++) {
		if (obj.scores[i] > result) {
			result = obj.scores[i];
		}
	}
	return result;
}
// Лучший вариант вернуть массив лучших оценок по индексам и сравнивать в Sort уже по ним (int *BestScore(Student&obj),int size)
void Sort(Student* (&obj), int size) {
	Student intermediate;
	for (int i{ 1 }; i < size; i++) {
		for (int j = i; BestScore(obj[j], size) >= BestScore(obj[j - 1], size) && j > 0; j--) {
			intermediate = obj[j - 1];
			obj[j - 1] = obj[j];
			obj[j] = intermediate;
		}
	}
}