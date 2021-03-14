#include <iostream>

using namespace std;

double ctok(double c)
{
	double k = c + 273.15;
	if (c >= -273.15) return k;
	else
	{
		cout << "Oops! Error!\n";
	}
}

int main()
{
	double c;
	cin >> c;
	double k = ctok(c);
	cout << k << endl;
}