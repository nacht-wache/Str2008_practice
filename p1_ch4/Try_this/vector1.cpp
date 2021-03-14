#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string>words;
	string temp;
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
			if (i == 0 || words[i-1]!=words[i])
			{
				cout << words[i] << endl;
			}
		}
}