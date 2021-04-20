/*Implement square() without using the multiplication operator; that is, do the
x*x by repeated addition (start a variable result at 0 and add x to it x times).
Then run some version of "the first progfanl" using that square().*/

/*#include <iostream>

using namespace std;

int square(int x) {
	int k = 0;
	int y = 0;
	for (int k; k < x; ++k) {
		y += x;
		}
	return y;
}

int main() {
	int x;
	cout << "please, enter the number you want to sqaure.\n";
	cin >> x;
	cout << x << '\t' << square(x) << endl;
}*/

#include <iostream>
#include <cmath>



unsigned square(unsigned x)
{
	std::cout << x << '\n';
	unsigned s = 0;

	for (unsigned add = x; x != 0; add += add, x >>= 1) {
		if ((x & 1) != 0) {
			s += add;
		}
	}
	return s;
}

int main()
{
	int x;
	std::cin >> x;
	std::cout << square(x) << '\n';
}