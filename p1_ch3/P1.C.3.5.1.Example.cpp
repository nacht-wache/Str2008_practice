#include <iostream>

using namespace std;

int main()
{
	string previous = " ";
	string current;
	while (cin >> current) {
		cout << previous << " pupsik " << current;
		if (previous == current)
			cout << "repeted word: " << current;
		previous = current;
	}
}