/*
An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().
*/


#include <iostream>
#include <vector>

using std::vector;

//int is better than int&
//int allocates 4 bytes, reference allocates 8 bytes
int fibonacci(int x, int y, vector<int>& v) {
    v[0] = {x};
    v[1] = {y};

    //we already have x and y in vector, so n-2
    //count {2} - start with 3d element
    for(int count {2}; ; ++count) {
        int var {x+y};

        if(var >= 0) {
            v[count] = {var};
            x = y;
            y = var;
        }
        //return an index of a previous to the out-of-range value
        else return count-1;
    }
}

int main() {
    int fNum = 1;
    int sNum = 2;
    vector<int> v(44,0); // 44 fibonacci's numbers can be stored in int
    vector<int>& rv = v;

    std::cout << rv[fibonacci(fNum, sNum, rv)] << '\n';

    return 0;
}
