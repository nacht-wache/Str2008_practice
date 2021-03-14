/* There is an old story that the emperor wanted to thank the inventor of
the game of chess and asked the inventor to name his reward. 
The inventor asked for one grain of rice for the first square, 2 for the second, 4
for the third, and so on, doubling for each of the 64 squares. That may
sound modest, but there wasn't that much rice in the empire! Write a
program to calculate how many squares are required to give the inventor
at least 1000 grains of rice, at least 1 ,000,000 grains, and at least
1 ,000,000,000 grains. You'll need a loop, of course, and probably an int
to keep track of which square you arc at, an int to keep the number of
grains on the current square, and an int to keep track of the grains on all
previous squares. 
We suggest that you write out the value of all your variables for each iteration ofthe loop so that you can see what's going on*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count = 0;
	int laps = 0;
	for (int i = 1; i < 65; i *= 2)
	{
		count += i;
		++laps;
	}
	cout << "64 squares - " << count << " - grains and " << laps << " laps.\n";

	for (int i = 1; count < 1001; i *= 2)
	{
		count += i;
		++laps;
	}
	cout << "1000 squares - " << count << " - grains and " << laps << " laps.\n";

	for (int i = 1; count < 1000001; i *= 2)
	{
		count += i;
		++laps;
	}
	cout << "1000000 squares - " << count << " - grains and " << laps << " laps.\n";

	for (int i = 1; count < 1000000001; i *= 2)
	{
		count += i;
		++laps;
	}
	cout << "1000000000 squares - " << count << " - grains and " << laps << " laps.\n";
}