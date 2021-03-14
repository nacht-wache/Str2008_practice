/*Write a program that "bleeps" out words that you don't like; that is, you
read in words using cin and print them again on cout. If a word is among a
few you have defined, you write out BLEEP instead of that word. Start with
one "disliked word" such as
string disliked = "Broccoli";
When that works, add a few more.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string>words;
	string temp;
	string disliked = "Broccoli";
	while (cin >> temp)
	{
		words.push_back(temp);
	}

	switch (words.size())
	{
	case 1:
		cout << "Number of words is " << words.size() << endl;
		break;
	default:
		cout << "Number of words are " << words.size() << endl;
		break;
	}

	sort(words.begin(), words.end());

	for (int i = 0; i < words.size(); ++i)
	{
		if (i == 0 || words[i - 1] != words[i])
		{
			if (words[i] == disliked)
			{
				cout << "BEEPED" << endl;
			}
			else 
			{
				cout << words[i] << endl;
			}
		}
	}
}