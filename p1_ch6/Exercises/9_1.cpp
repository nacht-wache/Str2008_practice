/*
Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. The program should
output "123 is 1 hundred and 2 tens and 3 ones". The number should be
output as an int value. Handle numbers with one, two, three, or four
digits. Hint: To get the integer value 5 of the character '5' subtract '0',
that is, '5'-'0'==5.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class no_digits {};
class too_many_digits {};

int main()
{
	try {
		vector<int>digit;
		vector<string>unit;

		unit.push_back(" ones ");
		unit.push_back(" tens ");
		unit.push_back(" hundreds ");;
		unit.push_back(" thousands ");
		unit.push_back(" tens of thousands ");
		unit.push_back(" hundreds of thousands ");
		unit.push_back(" millions ");
		unit.push_back(" tens of millions ");
		unit.push_back(" hundreds of millions ");

		cout << "Please enter an integer value no more than " <<
			unit.size() << "\ndigits followed by semicolon and a newline.\n";

		char ch;
		while (cin >> ch) {
			if (ch < '0' || '9' < ch) break; // IDK: break if ch less that '0' OR more than '9';
			digit.push_back(ch - '0');
		}

		if (digit.size() == 0) throw no_digits();
		if (digit.size() > unit.size()) throw too_many_digits();

		for (int i = 0; i < digit.size(); ++i)
			cout << char('0' + digit[i]);
		cout << endl;


		int num = 0;
		for (int i = 0; i < digit.size(); ++i) {
			if (digit[i]) // IDK: int 0 equal to bool false ? NO; IDKIDKIDK
				cout << digit[i] << unit[digit.size() - i - 1]; // IDK: num = 1234; digit[0] = 1; unit[4-0-1] = thousands;
																// we have list of units. get the unit means substract from digit.size() index of digit[i]
																// AND substract 1, cause we want to return index for unit. indexies start we 0. the fouth have index 3.
			num = num * 10 + digit[i];
		}

		cout << "\nthat is " << num << endl;
	}

	catch (no_digits) {
		cout << "Oops! No digits have been entered.\n";
		EXIT_FAILURE;
	}

	catch (too_many_digits) {
		cout << "Oops! Too many digits have been entered.\n";
		EXIT_FAILURE;
	}
}