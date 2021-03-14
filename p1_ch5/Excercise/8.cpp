/*
1. reads a series of numbers and stores them in a vector <int>. 
2. After the user inputs all the numbers he or she wishes to,
ask how many of the numbers the user wants to sum. 
3. For an answer N print the sum of the first N elements of the vector. 
4. Handle all inputs. For example, make sure to give an error message if the
user asks for a sum of more numbers than there are in the vector.

For example:
"Please enter some numbers (press '|' at prompt to stop):"
12 23 13 24 15
"Please enter how many of the numbers you wish to sum, starting
from the first:"
3
"The sum of the first 3 numbers : 12, 23, and 13 is 48."

_____

Modify the program from exercise 8 to use double instead of int. 
Also, make a vector of doubles containing the N-1 differences between adjacent values
and write out that vector of differences
*/

#include <iostream>
#include <vector>

using namespace std;

class exc_amount {};

class under_amount {};

int main()
{
	try
	{
		vector<double>numbers;
		vector<double>differences;
		
		char ExitTheLoop = '>';
		
		double nums = 0;
		int amount;
		double sum = 0;
		double diff = 0;

		cout << "Please enter any number. Then enter any symbol, but a number, to countine entering numbers or press '|' to stop. Repeat: \n";

		for (int i = 0; ExitTheLoop != '|'; ++i) {
			cin >> nums >> ExitTheLoop;
			numbers.push_back(nums);
		}

		for (int i = 1; i < numbers.size(); ++i)		{
			diff = numbers[i] - numbers[i - 1];
			differences.push_back(diff);
		}

		cout << "Numbers size is " << numbers.size() << endl;
		cout << "Please enter how many numbers you wish to sum, starting from the first:\n";
		cin >> amount;
		
		int int_conversion = numbers.size();

		if (amount > int_conversion) {
			cout << "idiot" << endl;
			throw exc_amount();
		}

		if (amount < 0) {
			throw under_amount();
		}

		for (int i = 0; i < (amount); ++i) {
			sum += numbers[i];
		}

		cout << "The sum of the first " << amount << " numbers is " << sum << endl;
		cout << "The vector of differences is: \n";

		for (int i = 0; i < differences.size(); ++i) {
			cout << differences[i] << ' ';
		}

		cout << endl;
	}

	catch (exc_amount) {
		cout << "Oops! You have exceed a size of vector.\n";
			return EXIT_FAILURE;
	}

	catch (under_amount) {
		cout << "Oops! You have understated a size of vector.\n";
			return EXIT_FAILURE;
	}

	catch (...) {
		cout << "Oops: unknown exception!\n";
		return EXIT_FAILURE;
	}
}
