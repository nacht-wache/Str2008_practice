/*

Write a function that given two vector<double>s price and weight
computes a value (an "index") that is the sum of all price[i)*weight[i].
Note that we must have weight.size()<=price.size().

*/

//initialize two vectors
//function = return sum of all price[i]*weight[i]

//boring

#include <vector>
#include <iostream>

double Function(const std::vector<double>& Price, const std::vector<double>& Weight)
{
    double SUM {0};

    for (unsigned int count {0}; count < Price.size(); count++)
    {
        SUM += Price[count] * Weight[count];
    }

    return SUM;
}

int main()
{
    std::vector<double>Price {100.13, 125.2, 200.5, 10.6, 40.3, 15.12};
    std::vector<double>Weight {2.5, 5.3, 7.8, 3.1, 9.5, 12};

    std::cout << Function(Price, Weight) << '\n';
    return 0;
}
