/*Write a program that prompts the user to enter some number of pennies
( 1-cent coins), nickels (5-cent coins), dimes ( 10-cent coins) , quarters (25-
cent coins) , half dollars (50-cent coins), and one-dollar coins ( 100-cent
coins). Query the user separately for the number of each size coin, e.g.,
"How many pennies do you have?" Then your program should print
out something like this:
You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.
You may have to usó your imagination to get the numbers to add up
right-justified, but try; it can be done. Make some improvements: if only
one of a coin is reported, make the output grammatically correct, e.g.,
" 14 dimes" and "1 dime" (not "1 dimes") . Also, report the sum in dollars
and cents, i.e., $5.73 instead of 573 cents.*/

#include <iostream>

using namespace std;

int main() {
	double pennies;
	double nickels;
	double dimes;
	double quarters;
	double half_dollars;
	double one_dollar;
	double sum;
	cout << "How many pennies do you have?\n";
	cin >> pennies;
	cout << "How many nickels do you have?\n";
	cin >> nickels;
	cout << "How many dimes do you have?\n";
	cin >> dimes;
	cout << "How many quarters do you have?\n";
	cin >> quarters;
	cout << "How many half dollars do you have?\n";
	cin >> half_dollars;
	cout << "How many one dollar coins do you have?\n";
	cin >> one_dollar;
	if (pennies == 1) {
		cout << "You have 1 pennie.\n";
	}
	else if (pennies == 0) {
		cout << "You don't have a penny coin.\n";
	}
	else {
		cout << "You have " << pennies << " pennies.\n";
	}
	if (nickels == 1) {
		cout << "You have 1 nickel.\n";
	}
	else if (nickels == 0) {
		cout << "You don't have a nickel coin.\n";
	}
	else {
		cout << "You have " << nickels << " nickels.\n";
	}
	if (dimes == 1) {
		cout << "You have 1 dime.\n";
	}
	else if (dimes == 0) {
		cout << "You don't have a dime coin.\n";
	}
	else {
		cout << "You have " << dimes << " dimes.\n";
	}
	if (quarters == 1) {
		cout << "You have 1 quarter.\n";
	}
	else if (quarters == 0) {
		cout << "You don't have a quarter coin.\n";
	}
	else {
		cout << "You have " << quarters << " quarters.\n";
	}
	if (half_dollars == 1) {
		cout << "You have 1 half dollar.\n";
	}
	else if (half_dollars == 0) {
		cout << "You don't have a half dollar coin.\n";
	}
	else {
		cout << "You have " << half_dollars << " half dollars.\n";
	}
	if (one_dollar == 1) {
		cout << "You have 1 one dollar coin.\n";
	}
	else if (one_dollar == 0) {
		cout << "You don't have a one dollar coin.\n";
	}
	else {
		cout << "You have " << one_dollar << " one dollar coins.\n";
	}
	sum = pennies + (nickels * 5) + (dimes * 10) + (quarters * 25) + (half_dollars * 50) + (one_dollar * 100);
	cout << "The value of all of your coins is $" << sum / 100 << " dollars and " << sum << " cents.\n";
}