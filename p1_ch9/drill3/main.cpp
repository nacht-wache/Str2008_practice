/*

This drill simply involves getting the sequence of versions of Date to work. For
each version define a Date called today initialized to June 25, 1978.
Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
Finally, output today and tomorrow using a << defined as in §9.8.

Your check for a valid date may be very simple. However, don't accept a
month that is not in the [1,12] range or day of the month that is not in the [1,31]
range. Test each version with at least one invalid date (e.g., 2004, 13, -5).

2. The version from §9.4.3

*/

#include <iostream>

class Date{
    int y, m, d;
public:
    Date(int yy, int mm, int dd)
    {
        if(yy < 0) throw std::out_of_range("range error: negative year.");
        if(mm < 1 || mm > 12) throw std::out_of_range("range error: month");
        if(dd < 1 || dd > 31) throw std::out_of_range("range error: day");

        y = yy;
        m = mm;
        d = dd;
    }

    void add_day(int n)
    {
        if(d == 31) {
            d = 1;
            if(m == 12) {
                m = 1;
                y += 1;
                return;
            }
            m += 1;
            return;
        }
        d += n;
    }

    int year() const {return  y;}
    int month() const {return m;}
    int day() const {return  d;}
};

std::ostream& operator << (std::ostream& os, const Date& name)
{
    return os << '(' << name.year()
              << ',' << name.month()
              << ',' << name.day()
              << ')' << std::endl;
}

int main()
{
    try {
        Date today(1978, 12, 31);


        Date tomorrow = today;

        tomorrow.add_day(1);

        std::cout << "today is: " << today << std::endl
                  << "tomorrow is: " << tomorrow << std::endl;
    }  catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

}
