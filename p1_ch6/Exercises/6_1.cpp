#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
I started writing the sentence() function and then invented the classification functions
is_noun(), etc., then I introduced the vectors of words to represent the classifications.

Those word classification vectors makes it trivial to enlarge the vocabulary.

The exercise didn't ask us to handle multiple statements, but why not?
*/

//errors list
class noun_error {};
class verb_error {};

vector<string>nouns;
vector<string>verbs;
vector<string>conj;

void init()
{
	nouns.push_back("C++");
	nouns.push_back("birds");
	nouns.push_back("fish");

	verbs.push_back("rules");
	verbs.push_back("swim");
	verbs.push_back("fly");

	conj.push_back("and");
	conj.push_back("or");
	conj.push_back("but");
}



bool is_noun(string w)
{
	for (int i = 0; i < nouns.size(); ++i) 
	{
		if (nouns[i] == w) return true;
	}
	return false;
}

bool is_verb(string w)
{
	for (int i = 0; i < verbs.size(); ++i)
	{
		if (verbs[i] == w) return true;
	}
	return false;
}

bool is_conjunction(string w)
{
	for (int i = 0; i < conj.size(); ++i)
	{
		if (conj[i] == w) return true;
	}
	return false;
}

bool sentence()
{
	string w;
	cin >> w;
	if (!is_noun(w)) return false;

	string w2;
	cin >> w2;
	if (!is_verb(w2)) return false;

	string w3;
	cin >> w3;
	if (w3 == ".") return true;
	if (!is_conjunction) return false;
	return sentence();
}

int main()
{
	try {
		init();

		while (cin)
		{
			bool b = sentence();
			if (b) {
				cout << "OK\n";
			}
			else {
				cout << "Not OK\n";
			}
			cout << "Try again\n";
		}
	}

	catch (...) {
		cout << "erron\n";
	}
}
/*double is_verb

double sentence()
{
	string w;
	cin >> w;
	if (!is_noun(w)) {
		throw noun_error();
	}*/