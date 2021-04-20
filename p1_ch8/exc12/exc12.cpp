/*

Write a function that
1) finds the smallest and the largest element of a vector argument
2) computes the mean and the median.

NB! Do not use global variables.

1) either return a struct containing the results
2) or pass them back through reference arguments.

Which of the two ways of returning several result values do you prefer and why?

*/

#include <iostream>
#include <vector>

struct Results
{
    double LargestNumber;
    double SmallestNumber;
    double Median;
    double Mean;
};

void CalculateReferences(const std::vector<double>& Numbers, double& LargestNumber, double& SmallestNumber, double& Median, double& Mean)
{

    //find the largest and the smallest
    for(unsigned int count {0}; count < Numbers.size(); count++)
    {
        if(LargestNumber < Numbers[count]) LargestNumber = Numbers[count];
        if(SmallestNumber > Numbers[count]) SmallestNumber = Numbers[count];
    }

    //calculate mean
    double Sum {0};
    for(unsigned int count {0}; count < Numbers.size(); count++)
    {
        Sum += Numbers[count];
    }
    Mean = Sum / 2;


    //calculate median
    int IsOdd = Numbers.size() % 2;
    switch (IsOdd) {
    case 0:
        Median = (Numbers[Numbers.size() / 2] + Numbers[Numbers.size()/2 + 1]) / 2;
        break;
    case 1:
        Median = Numbers[Numbers.size() / 2];
        break;
    default:
        std::runtime_error("Median issue");
        break;
    }
}

void CalculateStruct(const std::vector<double>& Numbers, Results& result)
{

    //find the largest and the smallest
    for(unsigned int count {0}; count < Numbers.size(); count++)
    {
        if(result.LargestNumber < Numbers[count]) result.LargestNumber = Numbers[count];
        if(result.SmallestNumber > Numbers[count]) result.SmallestNumber = Numbers[count];
    }

    //calculate mean
    double Sum {0};
    for(unsigned int count {0}; count < Numbers.size(); count++)
    {
        Sum += Numbers[count];
    }
    result.Mean = Sum / 2;


    //calculate median
    int IsOdd = Numbers.size() % 2;
    switch (IsOdd) {
    case 0:
        result.Median = (Numbers[Numbers.size() / 2] + Numbers[Numbers.size()/2 + 1]) / 2;
        break;
    case 1:
        result.Median = Numbers[Numbers.size() / 2];
        break;
    default:
        std::runtime_error("Median issue");
        break;
    }
}

int main()
{

    std::vector<double>Numbers {10,12.3,-5,3,8,3};

    double LargestNumber {Numbers[0]};
    double SmallestNumber {Numbers[0]};
    double Median {0};
    double Mean {0};

    CalculateReferences(Numbers, LargestNumber, SmallestNumber, Median, Mean);

    std::cout << "Output CalculateReferences results: " << '\n'
              << "the largest number is: " << LargestNumber << '\n'
              << "the smallest is: " << SmallestNumber << '\n'
              << "median is: " << Median << '\n'
              << "mean is: " << Mean << '\n';

    Results result;
    result = {Numbers[0],Numbers[0],0,0};

    CalculateStruct(Numbers, result);

    std::cout << "Output CalculateStruct results: " << '\n'
              << "the largest number is: " << result.LargestNumber << '\n'
              << "the smallest is: " << result.SmallestNumber << '\n'
              << "median is: " << result.Median << '\n'
              << "mean is: " << result.Mean << '\n';


    return 0;
}

