/*Create a program to find all the prime numbers between 1 and 100.
There is a classic method for doing this, called the "Sieve of Eratosthenes." If you don't know that method, get on the web and look it up.
Write your program using this method.*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>numbers;
	vector<int>primes1;
	vector<int>primes2;
	vector<int>primes3;
	vector<int>primes4;

	for (int i = 1; i < 100; ++i)
	{
		numbers.push_back(i);
	}
	
	for (int i = 2; i < numbers.size(); ++i)
	{
		if (numbers[i] % 2 != 0)
		{
			primes1.push_back(numbers[i]);
		}
	}

	for (int n = 1; n < primes1.size(); ++n)
	{
		if (primes1[n] % 3 != 0)
		{
			primes2.push_back(primes1[n]);
		}
	}

	for (int n = 1; n < primes2.size(); ++n)
	{
		if (primes2[n] % 5 != 0)
		{
			primes3.push_back(primes2[n]);
		}
	}
	
	primes4.push_back(2);
	primes4.push_back(3);
	primes4.push_back(5);
	primes4.push_back(7);
	for (int n = 1; n < primes3.size(); ++n)
	{
		if (primes3[n] % 7 != 0)
		{
			primes4.push_back(primes3[n]);
		}
	}

	for (int i = 0; i < primes4.size(); ++i)
	{
		cout << primes4[i] << endl;
	}
}