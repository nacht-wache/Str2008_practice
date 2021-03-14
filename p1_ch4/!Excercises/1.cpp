/*If we define the median of a sequence as "the number for which exactly
half of the elements of the sequence come before it and exactly half come
after it," fix the program in §4.6.2 so that it always prints out a median.
Hint: A median need not be an element of the sequence.*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
		vector<double> temps; 
		double temp;
		while (cin >> temp)
		{
			temps.push_back(temp);
		}

		double sum = 0;
		for (int i = 0; i < temps.size(); ++i) 
		{
			sum += temps[i];			
		}

		cout << "Average temperature: " << sum / temps.size() << endl;

		sort(temps.begin(), temps.end()); 
		
		if (temps.size() % 2 == 0)
		{
			cout << "Median temperature: " << (temps[(temps.size() / 2)] + temps[(temps.size() / 2)-1]) / 2 << endl;
		}
		else
		{
			cout << "Median temperature: " << temps[(temps.size() / 2)] << endl;
		}
}