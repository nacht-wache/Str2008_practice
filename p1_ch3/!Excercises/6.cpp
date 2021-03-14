/*Write a program that prompts the user to enter three integer values, and
then outputs the values in numerical sequence separated by commas. So,
if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
values are the same, they should just be ordered together. So, the input 4
5 4 should give 4, 4, 5.*/

/* modified the task to check if code works
instead of 'cin' used random number*/

#include <iostream>

using namespace std;

int main() {
	while (true) {
		int a;// = rand(); 
		int b;// = rand();
		int c;// = rand();
		cout << "Please, enter three numbers followed by 'enter'\n";
		cin >> a >> b >> c;
		if (a > b and b > c) {
			cout << c << ',' << b << ',' << a << endl;
		}
		if (a < b and b < c) {
			cout << a << ',' << b << ',' << c << endl;
		}
		if (a < b and b > c) {
			if (a > c) {
				cout << c << ',' << a << ',' << b << endl;
			}
			else {
				cout << a << ',' << c << ',' << b << endl;
			}

		}
		if (a > b and b < c) {
			if (a > c) {
				cout << b << ',' << c << ',' << a << endl;
			}
			else {
				cout << b << ',' << a << ',' << c << endl;
			}
		}
		if (a == b and b == c) {
			cout << a << ',' << b << ',' << c << endl;
		}
		if (a == b and b != c) {
			if (b > c) {
				cout << c << ',' << a << ',' << b << endl;
			}
			else {
				cout << a << ',' << b << ',' << c << endl;
			}
		}
		if (a != b and b == c) {
			if (a > b) {
				cout << b << ',' << c << ',' << a << endl;
			}
			else {
				cout << a << ',' << c << ',' << b << endl;
			}
		}
	}
}