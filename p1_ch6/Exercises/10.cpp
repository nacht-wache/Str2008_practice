/*

Design a program that asks users for two numbers, asks them whether
they want to calculate permutations or combinations, and prints out the
result. This will have several parts. Do an analysis of the above requirements. 
Write exactly what the program will have to do. Then, go into
the design phase. Write pseudo code for the program, and break it into
sub-components. This program should have error checking. Make sure
that all erroneous inputs will generate good error messages.

*/


#include <iostream>

using namespace std;

/*

Permutation(a,b) = a! / (a-b)!

Combination(a,b) = P(a-b) / b!

*/

//errors list
class wrong_op {};
class less_than_zero {};
class first_less_second {};
class fact_error {};

int Factorial(int num)
{
	if (num == 0) return 1;
	if (num >= 13) throw fact_error {}; //fact out of range of int starts with 13!
	int fact = 1;
	for (int i = 1; i < (num + 1); ++i) {
		fact *= i;
	}
	return fact;
}

int Permutation(int first_num, int second_num)
{
	return Factorial(first_num) / Factorial(first_num - second_num);
}

int Combination(int first_num, int second_num)
{
	return (Permutation(first_num, second_num) * (first_num - second_num)) / Factorial(second_num);
}


int main()
{
	try {
		while (true) {
			cout << "Please, enter separately two integer values [0..12], each followed by a new line.\n"
				<< "First one should be bigger than the second one. Note that!\n";
			int first_num, second_num;
			cin >> first_num >> second_num;

			//in-main checks list
			if (first_num < 0 || second_num < 0) throw less_than_zero();
			if (first_num < second_num) throw first_less_second();

			cout << "Type 'p' for permutation or 'c' for combination.\n";
			char op;
			cin >> op;
			switch (op)
			{
			case 'p':
				cout << "The permutation of " << first_num << " and " << second_num << " is " << Permutation(first_num, second_num) << endl;
				break;
			case 'c':
				cout << "The combination of " << first_num << " and " << second_num << " is " << Combination(first_num, second_num) << endl;
				break;
			default:
				throw wrong_op();
				break;
			}
		}
	}

	catch (wrong_op) {
		cout << "Oops! Wrong character has been entered. Try again with 'p' for permutation or 'c' for combination.\n";
		EXIT_FAILURE;
	}

	catch (less_than_zero) {
		cout << "Oops! U have entered negative value/values. Try again with positive ones.\n";
		EXIT_FAILURE;
	}

	catch (first_less_second) {
		cout << "Oops! First number is less than second one. Try again with first one bigger than second one.\n";
		EXIT_FAILURE;
	}

	catch (fact_error) {
		cout << "Oops! You have entered value/values bigger than 12. Type int can't take 13!: it's out of the range.\n";
		EXIT_FAILURE;
	}
}