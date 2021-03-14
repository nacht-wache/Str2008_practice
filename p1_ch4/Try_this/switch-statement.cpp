/*
Use the example above as a model for a program that converts yen, euros,
and pounds into dollars. If you like realism, you can find conversion rates on
the web.
*/

#include <iostream>

using namespace std;

int main() {
	const double ruble_per_dollar = 2.6352;
	const double ruble_per_euro = 3.0778;
	const double dollar_per_euro = 1.17;
	double money = 1;
	char from = 'a';
	char to = 'a';
	cout << "Please, enter an amount of money you want to convert.\n";
	cin >> money;
	cout << "Please, first enter currency 'from' then currency 'to'. Use 'r' for the rubles, 'd' for thedollars and 'e' for the euros.\n";
	cin >> from >> to;
	switch (from) {
	case 'r':
		switch (to) {
		case 'd':
			cout << money << " rubbles is " << money / ruble_per_dollar << " dollars.\n";
			break;
		case 'e':
			cout << money << " rubbles is " << money / ruble_per_euro << " euros.\n";
			break;
		}
		break;
	case 'd':
		switch (to) {
		case 'r':
			cout << money << " dollars is " << money * ruble_per_dollar << " rubbles.\n";
			break;
		case 'e':
			cout << money << " dollars is " << money / dollar_per_euro << " euros.\n";
			break;
		}
		break;
	case 'e':
		switch (to) {
		case 'r':
			cout << money << " euros is " << money * ruble_per_euro << " rubbles.\n";
			break;
		case 'd':
			cout << money << " euros is " << money / dollar_per_euro << " dollars.\n";
			break;
		}
		break;
	default:
		cout << "Sorry, I don't know a currency called " << from << endl;
	}
}