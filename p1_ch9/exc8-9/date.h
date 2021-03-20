#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
public:
    enum Month {
      jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
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

std::ostream& operator << (std::ostream& os, const Date& name);

#endif // DATE_H
