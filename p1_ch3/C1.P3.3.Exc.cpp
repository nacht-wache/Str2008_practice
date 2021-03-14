//Get the "name and age" example to run. Then, modify it to write out the age
//in months : read the input in years and multiply (using the • operator) by 12.
//Read the age into a double to allow for children who can be very proud of
//being 5.5 years old rather than just 5.

#include <iostream>

using namespace std;

int main()
{
	string name;
	double age;
	cout << "Please, enter your first name and age followed by enter.\n";
	cin >> name >> age;
	cout << "Hello, " << name << " age is " << age*12 << " months!\n";
}