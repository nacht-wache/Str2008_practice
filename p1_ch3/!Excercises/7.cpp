/* Do exercise 6, but with three string values. So, if the user enters the values "Steinbeck", "Hemingway", "Fitzgerald", the output should be
"Fitzgerald, Hemingway, Steinbeck".*/

#include <iostream>

using namespace std;

int main() {
	while (true) {
		string a;// = rand(); 
		string b;// = rand();
		string c;// = rand();
		cout << "Please, enter three words followed by 'enter'\n";
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