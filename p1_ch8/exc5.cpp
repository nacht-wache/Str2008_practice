/*
Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1 .
The first reverse function should produce a new vector
with the reversed sequence, leaving its original vector unchanged.
The other reverse function should reverse the elements
of its vector without using any other vectors (hint: swap).
*/

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

vector<int> reverseVector(const vector<int>& reverseVector)
{
    vector<int> reversedVector;

    for (int count = (reverseVector.size() - 1); count >= 0; --count)
    {
        reversedVector.push_back(reverseVector[count]);
    }
    return reversedVector;
}

vector<int> swapVector(const vector<int>& originalVector)
{

    for (int count {0}; count < (originalVector.size() - 2); ++count)
    {
        int FirstNumber {originalVector[count]};
        int SecondNumber {originalVector[count + 1]};

        std::swap(FirstNumber, SecondNumber);
    }

    return originalVector;
}

int main()
{
    vector<int>originalVector {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original vector.\n";
    for (int count {0}; count < originalVector.size(); ++count)
    {
        cout << originalVector[count] << '\n';
    }

    vector<int>reversedVector {reverseVector(originalVector)};
    cout << "Reversed vector.\n";
    for (int count {0}; count < reversedVector.size(); ++count)
    {
        cout << reversedVector[count] << '\n';
    }

    vector<int>swappedVector {swapVector(originalVector)};
    cout << "Swapped vector.\n";
    for (int count {0}; count < swappedVector.size(); ++count)
    {
       cout << swappedVector[count] << '\n';
    }

}
