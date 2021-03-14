#include <iostream>

using namespace std;

class neg_sqrt{};

class wrong_result{};

double quad_form(double a, double b, double c) {
	
	double x0, x1, x2;
	double quad_discr = pow(b, 2) - 4 * a * c;
	
	
	if (quad_discr < 0) throw neg_sqrt();
	
	else if (quad_discr > 0){
		x1 = (-b + sqrt(quad_discr)) / (2 * a);
		x2 = (-b - sqrt(quad_discr)) / (2 * a);
		cout << x1 << ' ' << x2 << endl;
		
		double quad_check_2roots1 = a * pow(x1, 2) + b * x1 + c;
		if (quad_check_2roots1 != 0.0) {
			cout << quad_check_2roots1 << endl;
			throw wrong_result();
		}

		double quad_check_2roots2 = a * pow(x2, 2) + b * x2 + c;
		if (quad_check_2roots2 != 0.0) {
			cout << quad_check_2roots2 << endl;
			throw wrong_result();
		}
	}

	else if (quad_discr == 0.0) {
		x0 = -b / (2 * a);
		cout << x0 << endl;

		double quad_check_1root = a * pow(x0, 2) + b * x0 + c;
		if (quad_check_1root != 0.0) throw wrong_result();
	}
}

int main() {
	try {
		double a, b, c;
		cin >> a >> b >> c;
		quad_form(a, b, c);
	}

	catch (neg_sqrt) {
		cout << "Oops! Negative value in sqrt().\n";
	}

	catch (wrong_result) {
		cout << "Oops! Wrong result though sqrt() is not negative.\n";
	}
}