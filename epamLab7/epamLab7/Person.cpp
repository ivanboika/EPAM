#include "Person.h"
Person::Person() {
	this->day_of_birth = 1;
	this->gender = "N/A";
	this->month_of_birth = 1;
	this->name = "N/A";
	this->patronymic = "N/A";
	this->surname = "N/A";
	this->year_of_birth = 1970;
}
Person::Person(std::string name, std::string surname, std::string patronymic) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->day_of_birth = 1;
	this->month_of_birth = 1;
	this->year_of_birth = 1970;
}
void Person::GetValidDate(STD string& obj) {
	int counter{ 0 };
	unsigned SWT{ 0 };
	STD string intermediate;
	while (counter<obj.size()) {
		if (obj.size() > 10) {
			return;
		}
		else {
			if (isalnum(obj[counter]) || obj[counter] != 46) {
				while (obj[counter] != '.' && counter < obj.size()) {
					intermediate.push_back(obj[counter]);
					counter++;
				}
				//day->month->year
				switch (SWT){
				case 0: {
					this->day_of_birth = (stoi(intermediate));
					SWT++;
					break;
				}
				case 1: {
					this->month_of_birth = stoi(intermediate);
					SWT++;
					break;
				}
				case 2: {
					this->year_of_birth = stoi(intermediate);
					break;
				}
				}
			}
			intermediate.clear();
		}
		counter++;
	}
}
void Person::GetValidString(std::string &obj) { // is_alpha check
	for (int i{ 0 }; i < obj.size(); i++) {
		if (isalpha(obj[i])) {}
		else {
			obj.erase(i);
			i--;
		}
	}
}
void Person::Show()const  {
	STD cout << "\nThe name is " << this->name << " " << this->surname << " " << this->patronymic << STD endl;
	STD cout << "Gender is " << this->gender << ". Date of birth is " << this->day_of_birth << "." << this->month_of_birth << "." << this->year_of_birth << STD endl;
}
void OutOf(std::ifstream& out, std::vector<Person>& obj) { // what if obj is empty?
	unsigned counter{ 0 };
	STD string intermediate;
	while (!out.eof()) {
		if (counter == obj.size() ) {
			obj.resize(counter + 1);
		}
		_GET
			if (intermediate[0] == '¹') { // pos string
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetN(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetS(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetP(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetG(intermediate);
				_GET
					obj[counter].GetValidDate(intermediate);
			}
			else
		counter++;
		counter++;
	}
	obj.pop_back();
}
void Person::SetN(STD string&obj) {
	this->name = obj;
}
void Person::SetS(STD string&obj) {
	this->surname = obj;
}
void Person::SetP(STD string&obj) {
	this->patronymic = obj;
}
void Person::SetG(STD string&obj) {
	this->gender = obj;
}
void SortSurname(STD vector<Person>&obj) {
	sort(obj.begin(), obj.end(), [](Person a, Person b) {return a.surname < b.surname; });
}
void Menu(int& choice,STD vector<Person>&obj) {
	switch (choice) {
	case 1: {
		STD ifstream out("Test1.txt");
		if (out.is_open()) {
			OutOf(out, obj);
		}
		else {
			STD cout << "File isn't open";
		}
		break;
	}
	case 2: {
		for (int i{ 0 }; i < obj.size(); i++) {
			obj[i].Show();
		}
		break;
	}
	case 3: {
		SortSurname(obj);
		break;
	}
	case 4: {
		int month{ 0 };
		STD cout << "\nEnter your month: "; STD cin >> month;
		assert(month > 0 && month < 13);
		STD find_if(obj.begin(), obj.end(), [=]( Person a) {
			if (a.month_of_birth == month) {
				a.Show();
				return false;
			}
			else
				return false;
			});
	}
	case 5: { //copy that and use sort
		Person intermediate;
		for (int i{ 0 }; i < obj.size(); i++) {
			if (obj[i].year_of_birth < intermediate.year_of_birth) {
				intermediate = obj[i];
			}
		}
		intermediate.Show();
		break;
	}
	case 6: {
		char symbol{ 'k' };
		STD cout << "\nEnter your month: "; symbol = _getche();
		assert(isalpha(symbol));
		STD find_if(obj.begin(), obj.end(), [=](Person a) {
			if (a.surname[0] == symbol) {
				a.Show();
				return false;
			}
			else
				return false;
			});
		break;
	}
	case 7: { //task in classroom
		int dividend{ 0 }, divider{ 0 };
		STD cout << "\nEnter dividend: "; 
		/*try {*/
			STD cin >> dividend;
		/*	if (isalpha(dividend)) {
				throw STD invalid_argument("\nNum should be num");
			}
		}
		catch (STD invalid_argument& a) {
			STD cout << a.what();
			dividend = 1;
		}*/
		assert(!isalnum(dividend));
		STD cout << "Enter divider: ";
		/*try {*/
			STD cin >> divider;
			/*if (isalpha(divider)) {
				throw STD invalid_argument("\nNum should be num\n");
			}
		}
		catch (STD invalid_argument& a) {
			STD cout << a.what();
			divider = 1;
		}*/
		assert(!isalnum(divider));
		/*Func(dividend, divider);*/
		Fraction a(dividend, divider);
	}
	case EXIT: {
		break;
	}
	default: {
		break;
	}
	}
}
double Func(int a, int b) {
	return a / b;
}
Fraction::Fraction(int a, int b) {
	try {
		if (b == 0)
			throw STD runtime_error("\nYou can't divide on a zero");
	}
	catch (STD runtime_error& a) {
		STD cout << a.what();
	}
}
Person& Person::operator=(const Person&obj) {
	this->day_of_birth = obj.day_of_birth;
	this->month_of_birth = obj.month_of_birth;
	this->year_of_birth = obj.year_of_birth;
	this->name = obj.name;
	this->surname = obj.surname;
	this->patronymic = obj.patronymic;
	return *this;
}
