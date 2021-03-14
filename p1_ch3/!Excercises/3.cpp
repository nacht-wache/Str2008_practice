#include <iostream>

using namespace std;

int main() {
	char c = 'x';
	int a1 = c;
	int a2 = 'x';
	char c1 = a1;
	cout << c << '\t' << a1 << '\t' << a2 << '\t' << c1 << endl;
}