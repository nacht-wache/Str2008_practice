#include <iostream>

void swap_v(int a, int b)
{
  int temp; temp = a; a = b; b = temp;

  std::cout << "1st parameter: " << a << " and 2d parameter:" << b << std::endl;
}

void swap_r(int& a, int& b)
{
  int temp; temp = a; a = b; b = temp;

std::cout << "1st parameter: " << a << " and 2d parameter:" << b << std::endl;
}

// doesn't compile. error assigning const type reference
// void swap_cr(const int& a, const int& b)
// {
//  int temp; temp = a; a = b; b = temp;
// }


void swap_cr(const int& a, const int& b)
{
    int temp = a + b;
    std::cout << "temp is " << temp << std::endl;
}

int main()
{

    int x = 7;
    int y = 9;

    std::cout << "x: " << x << " and y: " << y << std::endl; // x:7 and y: 9
    //swap local variables
    swap_v(x,y);                                             // 1st:9 and 2d: 7

    std::cout << "x: " << x << " and y: " << y << std::endl; // x:7 and y: 9
    //swap global variables
    swap_r(x,y);                                             // 1st:9 and 2d: 7

    std::cout << "x: " << x << " and y: " << y << std::endl; // x:9 and y: 7
    //OK
    swap_cr(x,y);                                            // temp is 16

    std::cout << "x: " << x << " and y: " << y << std::endl;  // x:9 and y: 7
    //swap local variables
    swap_v(7,9);                                             // 1st:9 and 2d: 7

    //doesn't compile. l-value excpected. 7 and 9 are r-values
    swap_r(7,9);

    const int cx = 7;
    const int cy = 9;

    //OK.swapping local variables
    swap_v(cx,cy);                                               // 1st:9 and 2d: 7
    std::cout << "cx: " << cx << " and cy: " << cy << std::endl; // cx:7 and cy: 9

    //doesn't compile. would lose const qualifier
    swap_r(cx,cy);

    //OK
    swap_cr(cx,cy);                                              // temp is 16

    //OK.though implicit conversion
    swap_v(7.7,9.9);                                             // 1st:9 and 2d: 7

    //doesn't compile. l-value excpected. 7.7 and 9.9 are r-values
    swap_r(7.7,9.9);

    //OK.though implicit conversion
    swap_cr(7.7,9.9);                                            // temp is 16

    double dx = 7.7;
    double dy = 9.9;


    swap_v(dx,dy);                                               //1st:9 and 2d:7
    std::cout << "dx: " << dx << " and dy: " << dy << std::endl; //dx: 7.7 and dy: 9.9

    //doesn't compile. there's no implicit conversion from double to int&
    swap_r(dx,dy);

    //OK
    swap_cr(dx,dy);                                              //temp is 16

}
