/*
2. Change the program to write out the smaller value is: followed by the
smaller ofthe nwnbers and the larger value is: followed by the larger value.
3. Augment the program so that it writes the line the numbers are equal
(only) if they are equal.
4. Change the program so that it uses doubles instead of ints.
5. Change the program so that it writes out the numbers are almost equal
after writing out which is the larger and the smaller if the two numbers
differ by less than 1.0/10000000.
6. Now change the body of the loop so that it reads just one double each
time around. Define two variables to keep track of which is the smallest
and which is the largest value you have seen so far. Each time through
the loop write out the value entered. If it's the smallest so far, write the
smallest so far after the nwnber. Ifit is the largest so far, write the largest
so far after the number.
7. Add a unit to each double entered; that is, enter values such as 10cm,
2.Sin, Sft, or 3.33m. Accept the four units: em, m, in, ft. Assume conversion factors 1m = 100cm, 1in = 2.54cm, 1ft == 12in. Read the unit indicator into a string.
8. Reject values without units or with "illegal" representations of units, such
as y, yard, meter, km, and gallons.
9. Keep track of the sum of values entered (as well as the smallest and the
largest) and the number of values entered. When you see the final 'I'
print the smallest, the largest, the number of values, and the sum of values. Note that to keep the sum, you have to decide on a unit to use for
that sum; use meters.
10. Keep all the values entered (converted into meters) in a vector. At the
end, write out those values.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<double>numbers;
	string unit;
	string unit_smallest;
	string unit_largest;
	const double m_cm = 100.0;
	const double in_cm = 2.54;
	const double ft_in = 12.0;
	double sum = 0;
	double entered_number;
	double entered_largest_number = 7;
	double entered_smallest_number = 5;
	double common_number = 0.0;
	double largest = 15.0;
	double smallest = 10.0;
	
	while (true)
	{
		cout << "please, enter the number and the unit. enter 0 or F to stop\n";
		cin >> entered_number >> unit;
		if (entered_number == 0 || unit == "F")
		{
			break;
		}
		if (unit == "y" || unit == "yard" || unit == "meter" || unit == "km" || unit == "gallons")
		{
			cout << "You entered the wrong value or haven't enter any for the unit. Try again.\n";
		}
		else
		{
			if (unit == "cm")
			{
				common_number = entered_number; // transfer to cm
			}
			else if (unit == "in")
			{
				common_number = entered_number * in_cm;
			}
			else if (unit == "ft")
			{
				common_number = entered_number * ft_in * in_cm;
			}
			else if (unit == "m")
			{
				common_number = entered_number * m_cm;
			}

			numbers.push_back(common_number);
			
			sort(numbers.begin(), numbers.end());

			if (common_number < smallest)
			{
				smallest = common_number;
				entered_smallest_number = entered_number;
				unit_smallest = unit;
			}
			if (common_number > largest)
			{
				largest = common_number;
				entered_largest_number = entered_number;
				unit_largest = unit;
			}
		}				
	}

	cout << "the smallest: " << entered_smallest_number << unit_smallest << ";\n";

	cout << "the largest: " << entered_largest_number << unit_largest << ";\n";

	for (int i = 0; i < numbers.size(); ++i)
	{
		sum += numbers[i];
	}
	cout << "the sum is: " << sum << "cm" << ";\n";
	for (int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << endl;
	}
}