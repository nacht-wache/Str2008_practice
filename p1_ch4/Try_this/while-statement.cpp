/*The character 'b' is char('a'+1 ), 'c' is char('a'+2), etc. Use a loop to write out
a table of characters with their corresponding integer values:
a 97
b 98
...
z 122*/

#include <iostream>

using namespace std;

int main() {
	char character = 'a';
	int number = 97;
	while (number < 123) {
		cout << character << ' ' << number << endl;
		++number;
		++character;
	}
}
