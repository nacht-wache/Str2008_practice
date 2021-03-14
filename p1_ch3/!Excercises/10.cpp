/*Write a program that takes an operation followed by two operands and
outputs the result. For example:
+ 100 3.14
• 4 5
Read the operation into a string called operation and use an if-statement
to figure out which operation the user wants, for example, if (opera·
tion=="+"). Read the operands into variables of type double. Implement
this for operations called +, -, *, /, plus, minus, mul, and div with their
obvious meanings.*/

#include <iostream>

using namespace std;

int main() {
	double number_one;
	double number_two;
	string operation;
	cout << "Please, enter two numbers.\n";
	cin >> number_one >> number_two;
	while (true) {
		cout << "Please, enter the operation you want to make under this numbers.\n";
		cin >> operation;
		if (operation == "+" or operation == "plus") {
			cout << "+" << '\t' << number_one << '\t' << number_two << '\t' << number_one + number_two << endl;
		}
		else if (operation == "-" or operation == "minus") {
			if (number_one > number_two) {
				cout << "-" << '\t' << number_one << '\t' << number_two << '\t' << number_one - number_two << endl;
			}
			else {
				cout << "-" << '\t' << number_two << '\t' << number_one << '\t' << number_two - number_one << endl;
			}
		}
		else if (operation == "*" or operation == "mul") {
			cout << "*" << '\t' << number_one << '\t' << number_two << '\t' << number_one * number_two << endl;
		}
		else if (operation == "/" or operation == "div") {
			cout << "/" << '\t' << number_one << '\t' << number_two << '\t' << number_one / number_two << endl;
		}
		else {
			cout << "You entered wrong operation. Try again.\n";
		}
	}
}