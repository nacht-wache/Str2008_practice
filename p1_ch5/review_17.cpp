#include <iostream>
#include <vector>

using namespace std;

class dev_zero {};

double div(double divisor, double devidend) {
	if (devidend == 0) throw (dev_zero());
	return divisor / devidend;
}

int main() {
	try {
		double divisor, devidend;
		cout << "Please, enter divisor and devidend\n";
		cin >> divisor >> devidend;
		div(divisor, devidend);
	}

	catch (dev_zero) {
		cout << "Oops! devision by zero\n";
	}
}