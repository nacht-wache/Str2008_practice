/*Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure
out what the number is (e.g., "Is the number you are thinking of less
than 50?"). Your program should be able to identify the number after
asking no more than seven questions. Hint: Use the < and <= operators
and the if-else construct.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
void slice(vector<int>&numrange, int first, int last)
{

	for (int i = first; i < last; ++i)
	{
		numrange.push_back(i);
	}

	auto it_b= numrange.begin();
	auto it_L = numrange.end();
	auto i = numrange.size() / 2;

	numrange.erase(it_b, it_h);

	char answer;
	if (answer == 'y')
	{

		slice(numrange, first, last);
	}
	else
	{
	}
}
int main()
{
	char answer;
	/*vector<int>odd;
	vector<int>even;

	for (int i = 1; (i <= 100) and (i % 2 == 0); ++i) // put all odd from 1 to 100 to vector odd
	{
		odd.push_back(i);
	}
	for (int i = 1; (i <= 100) and (i % 2 != 0); ++i) // put all even from 1 to 100 to vector even
	{
		even.push_back(i);
	}*/

	cout << "please, enter the first number and the last one.\n"; //read in range of numbers
	int first_number;
	int last_number;
	cin >> first_number >> last_number;

	vector<int>numbers;

	for (int i = first_number; i < last_number; ++i)
	{
		numbers.push_back(i);
	} //read in range of numbers

	sort(numbers.begin(), numbers.end());
	
	}

	/*
	if (answer == 'y')
	{
		cout << "Is the number less than 50?\n";
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Is the number less than 25?\n";
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Is the number less than 17?\n";
				cin >> answer;
				if (answer == 'y')
				{
					cout << "Is the number less than 9?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number devide by 4 without a remainder ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 4?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 4?\n";
							}
							else
							{
								cout << "Your number is 8?\n";
							}
						}
						else
						{
							cout << "Is the number you are thinking of is 2?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 2?\n";
							}
							else
							{
								cout << "Your number is 6?\n";
							}
						}
					}
					else
					{
						cout << "Is the number less than 13 ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 12?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 12?\n";
							}
							else
							{
								cout << "Your number is 10?\n";
							}
						}
					}
				}
				else
				{
					cout << "Is the number less than 9?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number devide by 4 without a remainder ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 2?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 2?\n";
							}
							else
							{
								cout << "Your number is 6?\n";
							}
						}
					}
				}
			}
			else
			{
				cout << "Is the number less than 39?\n";
				cin >> answer;
				if (answer == 'y')
				{
					cout << "Is the number less than 33?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number less than 29 ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 26?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 26?\n";
							}
							else
							{
								cout << "Your number is 28?\n";
							}
						}
					}
				}
			}

		}
		else
		{
			cout << "Is the number less than 75?\n";
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Is the number less than 17?\n";
				cin >> answer;
				if (answer == 'y')
				{
					cout << "Is the number less than 9?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number devide by 4 without a remainder ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 2?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 2?\n";
							}
							else
							{
								cout << "Your number is 6?\n";
							}
						}
					}
				}
			}
		}	
	}
	else
	{
		cout << "Is the number less than 50?\n";
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Is the number less than 25?\n";
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Is the number less than 17?\n";
				cin >> answer;
				if (answer == 'y')
				{
					cout << "Is the number less than 9?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number devide by 4 without a remainder ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 2?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 2?\n";
							}
							else
							{
								cout << "Your number is 6?\n";
							}
						}
					}
				}
			}

		}
		else
		{
			cout << "Is the number less than 25?\n";
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Is the number less than 17?\n";
				cin >> answer;
				if (answer == 'y')
				{
					cout << "Is the number less than 9?\n";
					cin >> answer;
					if (answer == 'y')
					{
						cout << "Is the number devide by 4 without a remainder ?\n";
						cin >> answer;
						if (answer == 'y')
						{
							cout << "Is the number you are thinking of is 2?\n";
							cin >> answer;
							if (answer == 'y')
							{
								cout << "Your number is 2?\n";
							}
							else
							{
								cout << "Your number is 6?\n";
							}
						}
					}
				}
			}
		}
	}*/
}