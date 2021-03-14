#include <iostream>

using namespace std;

int main()
{
	string previous = " ";
	string current;
	int number_of_words = 0;
	while (cin >> current) {
		if (previous == current)
			cout << ++number_of_words << " is number of repeated words\n"
			<< "repeated word: " << current << "\n";
			previous = current;
	}
}