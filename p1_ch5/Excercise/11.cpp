/*Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Fmd the largest
Fibonacci number that fits in an int. */

#include<iostream>

using namespace std;

int main()
{

		int Fibonacci = 0;
		int first_number = 0;
		int second_number = 1;

		cout << second_number << ' ';

		while (true)
		{
			Fibonacci = first_number + second_number;

			if (Fibonacci < 0) {
				cout << endl << "The largest Fibonacci number that fits int is: " << second_number << endl;
				return EXIT_SUCCESS;
			}

			else {
				cout << Fibonacci << ' ';

				first_number = second_number;
				second_number = Fibonacci;
			}
		}
}