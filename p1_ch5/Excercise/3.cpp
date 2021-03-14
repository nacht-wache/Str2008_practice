#include <iostream>

using namespace std;

double ctok(double c)
{
	double k = c + 273.15;
	return k;
}

int main()
{
	double c;
	cin >> c;
	if (c >= - 273.15)
	{
		double k = ctok(c);
		cout << k << endl;
	}
	else
	{
		cout << "Oops! Error!\n";
		return 1;
	}
}