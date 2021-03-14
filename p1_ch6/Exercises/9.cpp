/*
Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. The program should
output "123 is 1 hundred and 2 tens and 3 ones". The number should be
output as an int value. Handle numbers with one, two, three, or four
digits. Hint: To get the integer value 5 of the character '5' subtract '0',
that is, '5'-'0'==5.
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<char>digits;

int get()
{
	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
	{
		std::cin.putback(ch);
		digits.push_back(ch);
		double number;
		std::cin >> number;
		return number;
	}
	}
}

bool is_four(std::vector<char>any, int number)
{
	if (any.size() == 4) return true;
	return false;
}

bool is_three(std::vector<char>any, double number)
{
	if (any.size() == 3) return true;
	return false;
}

bool is_two(std::vector<char>any, double number)
{
	if (any.size() == 2) return true;
	return false;
}

bool is_one(std::vector<char>any, double number)
{
	if (any.size() == 1) return true;
	return false;
}


int main()
{
	double number = 0;
	
	while (true) {

		while (std::cin && (digits.size() < 4))
		{
			number = get();
		}

		if (is_one(digits, number)) {
			std::cout << number << " is " << digits[0] << " ones.\n";
			digits.clear();
		}

		else if (is_two(digits, number)) {
			std::cout << number << " is " << digits[0] << " tens " << digits[1] << " ones.\n";
			digits.clear();
		}

		else if (is_three(digits, number)) {
			std::cout << number << " is " << " thousand " << digits[0] << " hundred " << digits[1] << " tens " << digits[2] << " ones.\n";
			digits.clear();
		}

		else if (is_four(digits, number)) {
			std::cout << number << " is " << digits[0] << " thousand " << digits[1] << " hundred " << digits[2] << " tens " << digits[3] << " ones.\n";
			digits.clear();
		}
	}
}