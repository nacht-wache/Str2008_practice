/*Write a program that consists of a while-loop that (each time around the
loop) reads in two ints and then prints them. Exit the program when a
terminating '|' is entered.*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s, '|');
	istringstream ss(s);
	int a, b;
	while (ss >> a >> b)
	{
		cout << "(" << a << "," << b << ")\n";
	}

	if (cin.eof())
	{
		cout << "Hey, you didn't end with '|'!\n";
	}
}
/*#include <iostream>

using namespace std;

int main()
{
	
		int val1 = 0;
		int val2 = 0;
		while (std::cin.peek() != '|')
		{
			std::cin >> val1;
			std::cin >> val2;
			std::cout << val1 << " " << val2 << '\n';
		}

		return 0;
	
	while (true)
	{
		int first_number;
		int second_number;
		char terminate = '|';
		cin >> first_number >> second_number;
		char first = first_number;
		char second = second_number;
		cout << first << '\t' << first_number << '\t' << second << '\t' << second_number << endl;
		if (first == terminate and second == terminate)
		{
			return 1;
		}
		else if (first_number && second_number)
		{
			cout << first_number << '\t' << second_number << endl;
			return 2;
		}
		else
		{
			return 42;
		}
	}
}*/