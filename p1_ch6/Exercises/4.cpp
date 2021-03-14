/*
Define a class Name_value that holds a string and a value. 
Give it a constructor (a bit like Token). 
Rework exercise 19 in Chapter 4 to use a
vector< Name_ value> instead of two vectors.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//errors list
class entered_twice {};

class Name_value
{
public:
	string name;
	int value;
	Name_value(string name, int value)
		:name(name), value(value) { }
};

int main()
{
	try {
		vector<Name_value>v;
		
		int score = 0;
		string name = "name";
		Name_value token(name, score);
		while (cin >> name >> score && name != "NoName") {
			for (int i = 0; i < v.size(); ++i)
				if ( name == v[i].name) throw entered_twice();
			token.name = name;
			token.value = score;
			v.push_back(token);
		}

		for (int i = 0; i < v.size(); ++i) {
			cout << "Name is: " << v[i].name << " and score is: " << v[i].value << endl;
		}
	}

	catch (entered_twice) {
		cout << "Oops! Same name is entered twice.\n";
		EXIT_FAILURE;
	}

	catch (...) {
		cout << "Oops! Unknown error occured.\n";
		EXIT_FAILURE;
	}
}