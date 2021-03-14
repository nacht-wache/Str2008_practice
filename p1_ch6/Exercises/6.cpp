/*
returns some unknown for me exception. it'll funny to recheck the whole project. tried to solve the issue using classes :(
used Stroustrup's implementation in 6_1;
*/



/*
Write a program that checks if a sentence is correct according to the
"English" grammar in §6.4.1. Assume that every sentence is terminated
by a full stop (.) surrounded by whitespace. For example, birds fly but
the fish swim . is a sentence, but birds fly but the fish swim (terminating
dot missing) and birds fly but the fish swim. (no space before dot) are
not. For each sentence entered, the program should simply respond
"OK" or "not OK." Hint: Don't bother with tokens; just read into a
string using >>.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//errors list
class fish_error {};
class verb_error {};
class end_error {};

/*class Nouns
{
public:
	string noun;
	Nouns(string noun)
		:noun(noun){}
};

class Verbs
{
public:
	string word;
	Verbs(string word)
		:word(word) {}
};

class Conjuctions
{
public:
	string word;
	Conjuctions(string word)
		:word(word) {}
};

class Article
{
public:
	string word;
	Article(string word)
		:word(word) {}
};

string sentence_check(string sentence)
{

}
*/


string linear_search(vector<string>v, string s)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (s == v[i]) return v[4];
	}
}

string total_search(vector<string>v, vector<string>x, vector<string>y, string dot, string s)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (s == v[i]) return v[4];
	}

	for (int i = 0; i < x.size(); ++i)
	{
		if (s == x[i]) return x[4];
	}

	for (int i = 0; i < y.size(); ++i)
	{
		if (s == y[i]) return y[4];
	}

	if (s == dot) return "dot";
}


int main()
{
	try {
		vector<string>noun{ "C++ ", "birds ", "fish ", "noun " };
		vector<string>verb{ "rules ", "fly ", "swim ", "verb " };
		vector<string>conj{ "and", "or", "but", "conj" };
		string dot = " .";

		string previous_type;
		string sentence;
		string word;
		while (cin >> word)
		{
			previous_type = total_search(noun, verb, conj, dot, word);

			if (previous_type == dot) {
				cout << sentence;
				break;
			}

			else if (previous_type == "noun") {
				if (linear_search(noun, word) != "verb") throw verb_error();
			}

			else if (previous_type == "verb") {
				if (linear_search(noun, word) != "conj" || " .") throw end_error();
			}

			sentence += word;
		}
	}
	
	catch (verb_error) {
		cout << "Oops! Verb error!\n";
		return EXIT_FAILURE;
	}

	catch (end_error) {
		cout << "Oops! End error!\n";
		return EXIT_FAILURE;
	}
}