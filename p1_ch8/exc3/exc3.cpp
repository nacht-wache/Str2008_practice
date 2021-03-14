/*
Create a vector of Fibonacci numbers and print them using the function
from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n),
where integers x and y are ints, v is an empty vector<int>, and n is the
number of elements to put into v; v[O] will be x and v[1] will be y. A
Fibonacci number is one that is part of a sequence where each element is
the sum of the two previous ones. For example, starting with 1 and 2, we
get 1, 2, 3, 6, 9, 15, 24, . . . . Your fibonacci() function should make such
a series starting with its x and y arguments.
*/

//mistake in the problem situation. 1, 2, 3, 6 (2+3=5) etc.

#include <iostream>
#include <vector>

//const-by-reference when we don't want to parameters being changed by accident
void fibonacci(int& x, int& y, std::vector<int>& v, const int& n)
{
    //push back first two numbers
    v.push_back(x);
    v.push_back(y);

    //we already have x and y in vector, so n-2
    for(int count {0}; count < (n-2); ++count)
    {
        int var {x+y};
        v.push_back(var);
        x = y;
        y = var;
    }
}

//const-by-reference. we don't want to change parameters.
void print(const std::string& label, const std::vector<int>& v)
{

    std::cout << label << std::endl;

    for (int i {0}; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
}

int main()
{
    int fnum = 1;
    int snum = 2;
    int amount = 2;

    std::cout << "please, set amount of fibonacci's numbers to print  out.\n";
    std::cin >> amount;

    std::vector<int>vect;

    std::string label = std::to_string(amount) + " fibonacci's numbers.";


    fibonacci(fnum, snum, vect, amount);

    print(label, vect);

    return 0;
}
