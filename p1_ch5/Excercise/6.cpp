/*
absolute zero = -273.15 C || 0 K || -459.67 F
Planck temperature = 1.416784 * 10^32 K 
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s << ": " << i;
	error(os.str());
}

template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(string("info loss"));
	return r;
}

class int_double_f {};

class int_double_c {};

double ctof(double c) {
	
	double fahr;
	double abs_zero_C = -273.15;
	double plnck_temp_C = 1.416784e+32 + 273.15;
	
	if (c >= abs_zero_C && c <= plnck_temp_C){
		
		fahr = (c * 9 / 5) + 32;
		double int_dobule_F = fahr;
		narrow_cast<int>(int_dobule_F);
		return fahr;
	}
	
	else if (c <= abs_zero_C)	{
		cout << "Oops! Celsius absolute zero error occured.\n";
	}

	else if (c >= plnck_temp_C)	{
		cout << "Oops! Celsius Planck tempreture limit hase been violated.\n";
	}
	
}

double ftoc(double f) {
	double cels;
	double abs_zero_F = -459.67;
	double plnck_temp_F = (1.416784e+32 - 273.15) * 9 / 5 + 32;
	
	if (f >= abs_zero_F && f <= plnck_temp_F) {
		cels = (f - 32.0) * 5.0 / 9.0;
		double int_double_C = cels;
		narrow_cast<int>(int_double_C);
		return cels;
	}

	else if (f <= abs_zero_F) {
		cout << "Oops! Fahrenheit absolute zero error occured.\n";
	}

	else if (f >= plnck_temp_F) {
		cout << "Oops! Fahrenheit Planck tempreture limit hase been violated.\n";
	}
}

int main() {

	try {
		int celsius, fahrenheit;
		cin >> celsius >> fahrenheit;
		cout << ctof(celsius) << endl;
		cout << ftoc(fahrenheit) << endl;;

}

	catch (runtime_error) {
		cout << "Oops! double_int error occured.\n";
	}
}