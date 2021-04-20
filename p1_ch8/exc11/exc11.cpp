/*

Write a function maxv() that returns the largest element of a vector argument.

*/


//int/double types

#include <vector>
#include <iostream>

int maxv(const std::vector<int>& Numbers)
{
    int LargestNumber = Numbers[0];

    for(unsigned int count {0}; count < Numbers.size(); count++)
    {
        if(LargestNumber < Numbers[count]) LargestNumber = Numbers[count];
    }

    return LargestNumber;
}

int main()
{
    std::vector<int>Numbers {-100,-40,-10000,100,10000,100000000};

    std::cout << maxv(Numbers) << '\n';

    return 0;
}
