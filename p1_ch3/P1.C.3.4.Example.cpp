//read and compare names

#include <iostream>

using namespace std;

int main()
{
	cout << "Please, enter your first and second name\n";
	string fname;
	string sname;
	cin >> fname >> sname;
	if (fname == sname) cout << "You entered the same name twice\n";
	if (fname < sname) 
		cout << fname << " is alphabetically before\n";
	if (fname > sname) 
		cout << fname << " is alphabetically after\n";
}