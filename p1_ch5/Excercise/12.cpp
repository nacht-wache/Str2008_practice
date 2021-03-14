/*Implement a little guessing game called (for some obscure reason) .. Bulls
and Cows." The program has a vector of four integers in the range 0 to 9
and it is the user's task to discover those numbers by repeated guesses.
Say the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1 cow" because the user got one digit ( 1)
right and in the right position (a bull) and one digit (3) right but in the
wrong position (a cow). The guessing continues until the user gets four
bulls, that is, has the four digits correct and in the correct order. */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main() {

	int num;
	int bull = 0;
	int cow = 0;
	vector<int>digits;
	vector<int>user_digits;
	
	for (int i = 0; i < 4; ++i) {  //array of random digits from 0 to 9
		int number = getRandomNumber(0,9);
		digits.push_back(number);
	} 
	
	cout << "Please, enter 4 digits separated by space.\n";
	for (int i = 0; i < 4; ++i) { //user digits array
		cin >> num;
		user_digits.push_back(num);		
	}

	for (int i = 0; i < 4; ++i) {
		
		for (int k = 0; k < 4; ++k) {
			
			if (user_digits[i] == digits[k]) { //comparing values

				if (i == k) ++bull; // comparing indexies

				else ++cow;
			}
		}
	}
	
	cout << "Random digits are: " << endl;
	for (int i = 0; i < digits.size(); ++i) {
		cout << digits[i];
	}
	cout << endl;

	cout << "Users digits are: " << endl;
	for (int i = 0; i < user_digits.size(); ++i) {
		cout << user_digits[i];
	}
	cout << endl;

	cout << bull << " and " << cow << " cow" << endl;
}