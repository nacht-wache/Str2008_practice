/*Modify the "mini calculator" from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.*/

// division to 0 is not handled here

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int linear_search_string(vector<string>v, string x)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == x)
		{
			return i;
		}
	}
}

int linear_search_int(vector<int>v, int x)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == x)
		{
			return i;
		}
	}
}

int main()
{
	int num1_digit;
	int num2_digit;
	string num1_word;
	string num2_word;
	char op;
	
	vector<string>words{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<int>numbers;
	for (int i = 0; i < 9; ++i)
	{
		numbers.push_back(i);
	}
	
	/*cout << "please, enter the digits using words, separated by whitespace. then enter the operation (+, -, *, /)\n";
	while (cin >> num1_word >> num2_word >> op)
	{
		switch (op)
		{
		case '+':
			cout << linear_search_string(words, num1_word) + linear_search_string(words, num2_word) << endl;
			break;
		case '-':
			cout << linear_search_string(words, num1_word) - linear_search_string(words, num2_word) << endl;
			break;
		case '*':
			cout << linear_search_string(words, num1_word) * linear_search_string(words, num2_word) << endl;
			break;
		case '/':
			cout << linear_search_string(words, num1_word) / linear_search_string(words, num2_word) << endl;
			break;
		}		
	}*/
	
	cout << "please, enter the digits, separated by whitespace. then enter the operation (+, -, *, /)\n";
	while (cin >> num1_digit >> num2_digit >> op)
	{
		switch (op)
		{
		case '+':
			cout << linear_search_int(numbers, num1_digit) + linear_search_int(numbers, num2_digit) << endl;
			break;
		case '-':
			cout << linear_search_int(numbers, num1_digit) - linear_search_int(numbers, num2_digit) << endl;
			break;
		case '*':
			cout << linear_search_int(numbers, num1_digit) * linear_search_int(numbers, num2_digit) << endl;
			break;
		case '/':
			cout << linear_search_int(numbers, num1_digit) / linear_search_int(numbers, num2_digit) << endl;
			break;
		}
	}
}