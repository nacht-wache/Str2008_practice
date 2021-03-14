#include <iostream>

using namespace std;

int main() {
	while (true) {
		int miles;
		cout << "Please, enter the number of miles. It will be converted into kilometers.\n";
		cin >> miles;
		cout << "The " << miles << " miles is " << miles*1.609 << " kilometres." << endl;
	}
}