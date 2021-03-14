/*Write a program to test an integer value to determine if it is odd or even.
As always, make sure your output is clear and complete.In other words,
don't just output "yes" or "no." Your output should stand alone, like
"The value 4 is an even number." Hint: See the remainder(modulo) operator in §3.4.*/

#include <iostream>

using namespace std;

int main() {
	int a;
	while (true) {
		cout << "Please, enter the value of 'int' type.\n";
		cin >> a;
		if (a % 2 == 0) {
			cout << "The value " << a << " is an even number.\n";
		}
		else {
			cout << "The value " << a << " is an odd number.\n";
		}
	}
}