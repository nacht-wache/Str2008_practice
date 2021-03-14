/*
Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a vector
called names and the number to a vector called scores (in corresponding
positions, so that if names[7]=="Joe" then scores[7]==18). Terminate
input by the line No more ("more" will make the attempt to read another
integer fail). Check that each name is unique and terminate with an error
message if a name is entered twice. Write out all the (name,score) pairs,
one per line. 
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class entered_twice{};

int main()
{
	try {
		vector<string>names;
		vector<int>scores;

		int score;
		string name;
		while (cin >> name >> score && name != "NoName") {
			for (int i = 0; i < names.size(); ++i)
				if (name == names[i]) throw entered_twice();
			names.push_back(name);
			scores.push_back(score);
		}

		for (int i = 0; i < names.size(); ++i) {
			cout << "Name is: " << names[i] << " and score is: " << scores[i] << endl;
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