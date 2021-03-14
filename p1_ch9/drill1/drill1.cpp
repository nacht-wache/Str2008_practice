/*

This drill simply involves getting the sequence of versions of Date to work. For
each version define a Date called today initialized to June 25, 1978.
Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
Finally, output today and tomorrow using a << defined as in §9.8.

Your check for a valid date may be very simple. However, don't accept a
month that is not in the [1,12] range or day of the month that is not in the [1,31]
range. Test each version with at least one invalid date (e.g., 2004, 13, -5).

1. The version from §9.4.1
2. The version &om §9.4.2
3. The version from §9.4.3
4. The version from §9.7.1
5. The version from §9.7.4

*/

#include <iostream>
#include <ostream>

struct Date{
    int y;
    int m;
    int d;
};

void init_day(Date& name, int y, int m, int d)
{
    if(y < 0) throw std::out_of_range("range error: negative year.");
    if(m < 1 || m > 12) throw std::out_of_range("range error: month");
    if(d < 1 || d > 31) throw std::out_of_range("range error: day");

    name.y = y;
    name.m = m;
    name.d = d;
}

void add_day(Date& name, int add)
{
    if(name.d == 31) {
        name.d = 1;
        if(name.m == 12) {
            name.m = 1;
            name.y += 1;
            return;
        }
        name.m += 1;
        return;
    }
    name.d += add;
}

std::ostream& operator << (std::ostream& os, const Date& name)
{
    return os << '(' << name.y
              << ',' << name.m
              << ',' << name.d
              << ')' << std::endl;
}

int main()
{
    try {
        Date today;
        init_day(today, 1978, 1, 25);

        Date tomorrow = today;
        add_day(tomorrow, 1);

        std::cout << "today is: " << today << std::endl
                  << "tomorrow is: " << tomorrow << std::endl;
    }  catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

}
