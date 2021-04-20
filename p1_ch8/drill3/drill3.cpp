/*
 *
Write a program using a single ftle containing three namespaces X, Y, and
Z so that the following main() works correctly...
...Each namespace needs to define a variable called var and a function
called print() that outputs the appropriate var using cout.
 *
*/

#include <iostream>

namespace X {

int var {0};

void print()
{
    std::cout << var << '\n';
}
}

namespace Y {

int var {0};

void print()
{
    std::cout << var << '\n';
}
}

namespace Z {

int var {0};

void print()
{
    std::cout << var << '\n';
}
}

int main()
{
    X::var = 7;           // assign 7 to X's var
    X::print();           // print X's var: 7
    using namespace Y;
    var = 9;              // assign 8 to Y's var
    print();              // print Y's var: 9
    {
        using Z::var;
        using Z::print;
        var = 11;         // assign 11 to Z's var
        print();          // print Z's var: 11
    }
    print();              // print Y's var: 9. under namepspace Y
    X::print();           // print X's var: 7
}
