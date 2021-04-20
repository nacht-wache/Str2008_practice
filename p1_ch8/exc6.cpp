/*
Write versions of the functions from exercise 5, but with a vector<String>.
*/


#include <vector>
#include <iostream>
#include <string>

std::vector<std::string>OriginalVector {"zero", "one", "two", "three", "four", "five"};

void ReversedVector(std::vector<std::string>& OriginalVector)
{
    std::vector<std::string>ReversedVector;

    for(int count = (OriginalVector.size()-1); count >= 0; --count)
    {
        ReversedVector.push_back(OriginalVector[count]);
    }

    std::cout << "reversed vector.\n";
    for(int count {0}; count < ReversedVector.size(); ++count){
        std::cout << ReversedVector[count] << '\n';
    }
}

void SwapReversedVector(std::vector<std::string>& OriginalVector)
{

    for(int count {0}; count < (OriginalVector.size()-1); ++count)
    {
        std::string FirstNumber {OriginalVector[count]};
        std::string SecondNumber {OriginalVector[count+1]};

        std::swap(FirstNumber, SecondNumber);
    }

    std::cout << "swap() reversed vector.\n";
    for(int count {0}; count < OriginalVector.size(); ++count){
        std::cout << OriginalVector[count] << '\n';
    }
}


int main()
{
    std::cout << "orig vector.\n";
    for(int count {0}; count < OriginalVector.size(); ++count){
        std::cout << OriginalVector[count] << '\n';
    }

    ReversedVector(OriginalVector);
    SwapReversedVector(OriginalVector);
}
