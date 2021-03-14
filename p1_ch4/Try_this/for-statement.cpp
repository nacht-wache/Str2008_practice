/*Rewrite the character value example from the previous Try this to use a for loop. 
Then modify your program to also get a table of the integer values for
uppercase letters and digits.*/

#include <iostream>

using namespace std;

int main() {
	for (char character = 'a'; character <= 'z'; ++character) {
		int number = character;
		cout << character << ' ' << number << endl;
	}  
}
