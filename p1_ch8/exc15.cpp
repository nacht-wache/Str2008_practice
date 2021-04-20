/*

Can we declare a non-reference function argument const (e.g.,
void f(const int);)? What might that mean? Why might we want to do that?
Why don't people do that often? Try it; write a couple of small programs
to see what works

*/

#include <vector>
#include <iostream>

//non-reference, cause 1) you can't refere to an empty object (e.g. declared and uninitialized std::vector<int>Something)
//AND
//const, cause 1) you want to perform an operation onto the exactly same object (specifically if it's empty)
//FALSE

int main()
{

}
