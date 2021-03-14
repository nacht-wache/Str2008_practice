/*
print out valuess. 
insert test to caught all errors. 
answer: how do you know that you caught all errors? valid answer is possible.

*/

#include <iostream>

using namespace std;

int area(int x, int y)
{
	return x * y;
}

int framed_area(int x, int y)
{
	const int framed_width = 2;
	return area(x - framed_width, y - framed_width);
}

int f(int x, int y, int z)
{
	int area1 = area(x, y);
	if (area1 <= 0)
	{
		cout << "non-positive area. check for the args" << endl;
		return 1;
	}
	int area2 = framed_area(3, z);
	if (z <= 3)
	{
		cout << "non-positive 2nd argument of area() called by framed_area" << endl;
		return 2;
	}
	int area3 = framed_area(x, z);
	if (x <= 3 || z <= 3)
	{
		cout << "non-positive 1st or 2nd arg of area() called by framed_area" << endl;
		return 3;
	}
	double ratio = double(area1) / area3;
	if (area3 == 0)
	{
		cout << "error: devision by 0. area3 called by ratio is '0'" << endl;
		return 4;
	}
	cout << area1 << ' ' << area2 << ' ' << area3 << ' ' << ratio << endl;
}

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	f(x, y, z);
}