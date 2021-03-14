/*
Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1 .
The first reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged.
The other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).
*/

#include <vector>
#include <iostream>

std::vector<int>OriginalVector {0,1,2,3,4,5,6,7,8,9,10};

void ReversedVector(std::vector<int>& OriginalVector)
{
    std::vector<int>ReversedVector;

    for(int count = (OriginalVector.size()-1); count >= 0; --count)
    {
        ReversedVector.push_back(OriginalVector[count]);
    }

    std::cout << "reversed vector.\n";
    for(int count {0}; count < ReversedVector.size(); ++count){
        std::cout << ReversedVector[count] << std::endl;
    }
}

void SwapReversedVector(std::vector<int>& OriginalVector)
{

    for(int count {0}; count < (OriginalVector.size()-1); ++count)
    {
        int FirstNumber {OriginalVector[count]};
        int SecondNumber {OriginalVector[count+1]};

        std::swap(FirstNumber, SecondNumber);
    }

    std::cout << "swap() reversed vector.\n";
    for(int count {0}; count < OriginalVector.size(); ++count){
        std::cout << OriginalVector[count] << std::endl;
    }
}


int main()
{
    std::cout << "orig vector.\n";
    for(int count {0}; count < OriginalVector.size(); ++count){
        std::cout << OriginalVector[count] << std::endl;
    }

    ReversedVector(OriginalVector);
    SwapReversedVector(OriginalVector);
}
