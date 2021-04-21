/*
Create a vector of Fibonacci numbers and print them using the function
from exercise 2.
 1. To create the vector, write a function, fibonacci(x,y,v,n),
where integers x and y are ints, v is an empty vector<int>, and n is the
number of elements to put into v;
 2. v[O] will be x and v[1] will be y.
 A Fibonacci number is one that is part of a sequence where each element is
the sum of the two previous ones. For example, starting with 1 and 2, we
get 1, 2, 3, 6, 9, 15, 24, . . . . Your fibonacci() function should make such
a series starting with its x and y arguments.
*/

//there is a mistake in the problem situation. 1, 2, 3, 6 (2+3=5) etc.

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::string;

//int is better than int&, vector& is better than vector
//int allocates 4 bytes, vector allocates 24 bytes for each element, reference allocates 8 bytes
void fibonacci(int x, int y, vector<int>& v, int n)
{
    v[0] = {x};
    v[1] = {y};

    //count {2} - start with 3d element
    for (int count {2}; count < (n); ++count)
    {
        int var {x+y};
        v[count] = {var};
        x = y;
        y = var;
    }
}

void print(const string& label, const vector<int>& v)
{
    cout << label << '\n';

    for (int count {0}; count < v.size(); ++count)
    {
        cout << v[count] << '\n';
    }
}

int main()
{
    int fNum {0};
    int sNum {1};
    int amount {2};

    cout << "please, set amount of fibonacci's numbers to print out.\n";
    std::cin >> amount;

    vector<int> v(amount, 0);

    string label = std::to_string(amount) + " fibonacci's numbers.";

    fibonacci(fNum, sNum, v, amount);

    print(label, v);

    return 0;
}
