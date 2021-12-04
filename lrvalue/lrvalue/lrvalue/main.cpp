#include"MyStr.h"
//RVO
int main() {
	std::string a{ "aba" };
	MyStr str(a);
	MyStr new_str(std::move(MyStr("\na")));
	new_str.Show();
	str = new_str;
	std::cout << std::endl;
	a = "qwerty";
	MyStr new_((std::move(MyStr("rrrrrrr"))));
	MyStr what(new_);
	what.Show();
	//what = MyStr("AMOGUS");
	std::cout << "\nMOVE: \n";
	TextView t(MyStr("ab"));
	std::cout << "\n";
	t.Show();
	return 0;
}
