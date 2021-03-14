/*
Redo the "Bulls and Cows" game from exercise 12 in Chapter 5 to use
four letters rather than four digits.
*/

/* 

Implement a little guessing game called(for some obscure reason) ..Bulls
and Cows." The program has a vector of four integers in the range 0 to 9
and it is the user's task to discover those numbers by repeated guesses.
Say the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1 cow" because the user got one digit(1)
right and in the right position(a bull) and one digit(3) right but in the
wrong position(a cow).The guessing continues until the user gets four
bulls, that is, has the four digits correctand in the correct order.

*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
	try {
		char letter;
		int bull = 0;
		int cow = 0;
		vector<char>letters;
		vector<char>user_letters;

		for (int i = 0; i < 4; ++i) {  //array of letters
			char lett;
			cin >> lett;
			letters.push_back(lett);
		}

		cout << "Please, enter 4 letters.\n";
		for (int i = 0; i < 4; ++i) { //user letters array
			cin >> letter;
			user_letters.push_back(letter);
		}

		for (int i = 0; i < 4; ++i) {

			for (int k = 0; k < 4; ++k) {

				if (user_letters[i] == letters[k]) { //comparing values

					if (i == k) ++bull; // comparing indexies

					else ++cow;
				}
			}
		}

		cout << "Random digits are: " << endl;
		for (int i = 0; i < letters.size(); ++i) {
			cout << letters[i];
		}
		cout << endl;

		cout << "Users digits are: " << endl;
		for (int i = 0; i < user_letters.size(); ++i) {
			cout << user_letters[i];
		}
		cout << endl;

		cout << bull << " and " << cow << " cow" << endl;
	}

	catch (...) {
		cout << "Oops! Error occured.\n";
		return EXIT_FAILURE;
	}
}