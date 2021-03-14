#include <iostream>
#include <std_lib_facilities.h>

using namespace std;

void error(string s)
{
	throw runtime_error(s);
}

int area(int lenght, int width)
{
	if (lenght <= 0 || width <= 0) error("area() pre-condition");
	int x = lenght * width;
	if (x <= 0)	error("area() post-condition");
	return x;
}

int main() {
	int lenght, width;
	cin >> lenght >> width;
	cout << area(lenght, width) << endl;
}