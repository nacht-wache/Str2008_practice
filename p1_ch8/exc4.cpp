/*
An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().
*/


#include <iostream>
#include <vector>

//const-by-reference when we don't want to parameters being changed by accident
int fibonacci(int& x, int& y)
{
    int var {x+y};

    while(var > 0 && x > 0 && y > 0)
    {
        x = y;
        y = var;
        var = x+y;
    }
    return x;
}

int main()
{
    int fnum = 1;
    int snum = 2;

    std::cout << fibonacci(fnum, snum) << '\n';

    return 0;
}
