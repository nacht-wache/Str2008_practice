/*Write a program that converts spelled-out numbers such as "zero" and
"two" into digits, such as 0 and 2. When the user inputs a number, the
program should print out the corresponding digit. Do it for the values 0,
1 , 2, 3, and 4 and write out "not a number I know" if the user enters
something that doesn't correspond, such as "stupid computer!"*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	while (true) {
		string word;
		cout << "Please, enter a number frome the massive {0, 1, 2, 3, 4} using words.\n";
		cin >> word;
		if (word == "zero") {
			cout << '0' << endl;
		}
		else if (word == "one") {
			cout << '1' << endl;
		}
		else if (word == "two") {
			cout << '2' << endl;
		}
		else if (word == "three") {
			cout << '3' << endl;
		}
		else if (word == "four") {
			cout << '4' << endl;
		}
		else {
			cout << "Stupid computer!\n";
		}
		
	}
}