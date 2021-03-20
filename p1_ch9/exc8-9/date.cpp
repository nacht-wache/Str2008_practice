#include "date.h"

Date::Date(int yy, Month mm, int dd)
    :y(yy), m(mm), d(dd)
{
    if(yy < 0) throw std::out_of_range("range error: negative year.");
    if(mm < 1 || mm > 12) throw std::out_of_range("range error: month");
    if(dd < 1 || dd > 31) throw std::out_of_range("range error: day");
};

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
              << ')' << '\n';
}
