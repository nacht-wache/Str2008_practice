/*

This drill simply involves getting the sequence of versions of Date to work. For
each version define a Date called today initialized to June 25, 1978.
Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
Finally, output today and tomorrow using a << defined as in §9.8.

Your check for a valid date may be very simple. However, don't accept a
month that is not in the [1,12] range or day of the month that is not in the [1,31]
range. Test each version with at least one invalid date (e.g., 2004, 13, -5).

2. The version from §9.7.41

*/

#include <iostream>

class Year {
    static const int min = 1800;
    static const int max = 2200;
public:
    Year(int x) : y(x) {if (x < min || max < x) throw std::out_of_range("range error: year");}
    int year() const {return y;}
private:
    int y;
};

class Date{
public:
    enum Month {
      jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(Year y, Month m, int d);

    Year year() const {return y;}
    Month month() const {return m;}
    int day() const {return d;}

    void add_day();
private:
    Year y;
    Month m;
    int d;
};

Date::Date(Year yy, Month mm, int dd)
    :y(yy), m(mm), d(dd)
{
    if(mm < 1 || mm > 12) throw std::out_of_range("range error: month");
    if(dd < 1 || dd > 31) throw std::out_of_range("range error: day");
}

void Date::add_day()
{
    // i'm not able to overload '+=' operator yet
    /*
    for(int count = 0; count < n; count++)
    {
        if(this->d == 31) {
                this->d = 1;
                if(this->m == dec) {
                    this->m = jan;
                    this->y += 1;
                    return;
                }
                this->m = Month(m+1);
                return;
            }*/
            this->d += 1;
    }

std::ostream& operator << (std::ostream& os, const Year& name)
{
    return  os << name.year();
}


std::ostream& operator << (std::ostream& os, const Date& name)
{
    return os << '(' << name.year()
              << ',' << name.month()
              << ',' << name.day()
              << ')' << '\n';
}

int main()
{
    try {
        Date today(Year(1958), Date::jan, 25);


        Date tomorrow = today;

        tomorrow.add_day();

        std::cout << "today is: " << today << '\n'
                  << "tomorrow is: " << tomorrow << '\n';
    }  catch (std::out_of_range& e) {
        std::cout << e.what() << '\n';
    }

}
