/*

This drill simply involves getting the sequence of versions of Date to work. For
each version define a Date called today initialized to June 25, 1978.
Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
Finally, output today and tomorrow using a << defined as in §9.8.

Your check for a valid date may be very simple. However, don't accept a
month that is not in the [1,12] range or day of the month that is not in the [1,31]
range. Test each version with at least one invalid date (e.g., 2004, 13, -5).

2. The version from §9.7.4

*/

#include <iostream>

class Date{
public:
    enum Month {
      jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd);

    int year() const {return  y;}
    Month month() const {return m;}
    int day() const {return  d;}

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
private:
    int y, d;
    Month m;
};

Date::Date(int yy, Month mm, int dd)
    :y(yy), m(mm), d(dd)
{
    if(yy < 0) throw std::out_of_range("range error: negative year.");
    if(mm < 1 || mm > 12) throw std::out_of_range("range error: month");
    if(dd < 1 || dd > 31) throw std::out_of_range("range error: day");
}

void Date::add_day(int n)
{
    for(int count = 0; count < n; count++)
    {
        if(d == 31) {
                d = 1;
                add_month(1);
            }
        else
            d += 1;
    }
}

void Date::add_month(int n)
{
    for(int count = 0; count < n; count++){
    if(m == dec) {
        m = jan;
        add_year(1);
        return;
    }
    this->m = Month(m+1);
    }
}

void Date::add_year(int n)
{
   y += n;
}

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
        Date today(1958, Date::dec, 31);


        Date tomorrow = today;

        tomorrow.add_day(3);

        std::cout << "today is: " << today << std::endl
                  << "tomorrow is: " << tomorrow << std::endl;
    }  catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

}
