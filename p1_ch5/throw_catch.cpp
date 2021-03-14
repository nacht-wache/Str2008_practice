//area check doesn't work. only check by parameters. why? function check? is t possible at all? 

#include <iostream>

using namespace std;

class Bad_area {};

int area(int length, int width)
{
	if (length <= 0 || width <= 0) throw Bad_area(); // here
	return length * width;
}

int framed_area(int length, int width) {
	return area(length - 2, width - 2);
}

int main() {
	try {
		int x = -1;
		int y = 2;
		int z = 4;
		int area1 = area(x, y);
		int area2 = framed_area(3, z);
		int area3 = framed_area(y, z);
		double ration = area1 / area3;
	}

	catch (Bad_area) {
		cout << "Oops! bad arguments to area()\n";
	}
}