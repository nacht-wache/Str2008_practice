/*
Write versions of the functions from exercise 5, but with a vector<String>.
*/


#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::vector;

vector<string>originalVector {"zero", "one", "two", "three", "four", "five"};

void ReversedVector(vector<string>& OriginalVector)
{
    vector<string>ReversedVector;

    for (int count = (OriginalVector.size()-1); count >= 0; --count)
    {
        ReversedVector.push_back(OriginalVector[count]);
    }

    cout << "reversed vector.\n";
    for (int count {0}; count < ReversedVector.size(); ++count)
    {
        cout << ReversedVector[count] << '\n';
    }
}

void SwapReversedVector(vector<string>& OriginalVector)
{

    for (int count {0}; count < (OriginalVector.size()-1); ++count)
    {
        string FirstNumber {OriginalVector[count]};
        string SecondNumber {OriginalVector[count+1]};

        std::swap(FirstNumber, SecondNumber);
    }

    cout << "swap() reversed vector.\n";
    for (int count {0}; count < OriginalVector.size(); ++count)
    {
        cout << OriginalVector[count] << '\n';
    }
}


int main()
{
    cout << "orig vector.\n";
    for (int count {0}; count < originalVector.size(); ++count)
    {
        cout << originalVector[count] << '\n';
    }

    ReversedVector(originalVector);
    SwapReversedVector(originalVector);
}
