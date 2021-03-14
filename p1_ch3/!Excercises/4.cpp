/*
Write a program that prompts the user to enter two integer values. Store
these values in int variables named val1 and vall. Write your program to
determine the smallest, largest, sum, difference, product, and ratio of
these values and report them to the user.
*/

#include <iostream>

using namespace std;

int main() {
	double val1; // used double for the best effieciency of the task
	double vall;
	cout << "Please, enter two numbers\n";
	cin >> val1 >> vall;
	double largest; // store the largest and the smallest value
	double smallest; // that is for a difference will be positive
	if (val1 > vall) {
		largest = val1;
		smallest = vall;
		cout << "The largest one is " << largest << "\n";
		cout << "The smallest one is " << smallest << "\n";
		cout << "The difference of numbers is " << largest - smallest << endl; // count difference within if-statement
		}
	else {
		largest = vall;
		smallest = val1;
		cout << "The largest one is " << largest << "\n";
		cout << "The smallest one is " << smallest << "\n";
		cout << "The difference of numbers is " << largest - smallest << endl;
	}
	cout << "The product of numbers is " << val1 * vall << endl;
	cout << "The sum of nubers is " << val1 + vall << endl;
	cout << "The ratio of first number to the second one is " << val1 / vall << endl;
}