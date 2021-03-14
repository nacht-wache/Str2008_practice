//Get this little program to run.Then, modify it to read an int rather than a
//double. Note that sqrt() is not defined for an int so assign n to a double and
//take sqrt() of that. Also, "exercise" some other operations. Note that for ints I
//is integer division and % is remainder(modulo), so that 512 is 2 (and not 2.5
//	or 3) and 5 % 2 is 1. The definitions of integer •, / , and % guarantee that for
//	two positive ints aand b we have alb • b + a % b == a.

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	cout << "Please, enter a integer value\n";
	int n;
	cin >> n;
	cout << "n == " << n
		<< "\nn + 1 = " << n + 1
		<< "\nthree times n == " << 3*n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n*n
		<< "\nhalf of n == " << n/2
		<< "\nsquare root of n == " << sqrt(n)
		<< endl;
}