/*
Make a vector holding the ten string values "zero", "one", . . . "nine".
Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same proC H A PT E R 4 E X E R C I S E S
gram, using the same input loop, convert spelled-out numbers into their
digit form; e.g., the input seven gives the output 7.
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int linear_search(vector<string>v, string x)
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
	vector<string>words{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<int>digits;
	for(int i = 0; i < 9; ++i)
	{
		digits.push_back(i);
	}
	
	cout << "enter a digit.\n";
	string digit;
	
	while (cin >> digit)
	{
		cout << digits[linear_search(words, digit)] << endl;
	}
}