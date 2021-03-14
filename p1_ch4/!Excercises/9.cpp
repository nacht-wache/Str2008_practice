/*Try to calculate the number of rice grains that the inventor asked for in
exercise 8 above. You'll find that the number is so large that it won't fit in
an int or a double. Observe what happens when the number gets too
large to represent as an int and as a double. What is the largest number
of squares for which you can calculate the exact number of grains (using
an int)? 
What is the largest number of squares for which you can calculate the approximate number of grains (using a double)?*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int squares = 0;
	int count_int = 0;
	double count_db = 0.0;
	for (int i = 1; squares < 65; i *= 2)
	{
		count_int += i;
		++squares;
		cout << squares << '\t' << i << endl;
	}
	
	squares = 0;

	for (double i = 1; squares < 65; i *= 2)
	{
		count_db += i;
		++squares;
		cout << squares << '\t' << i << endl;
	}
}