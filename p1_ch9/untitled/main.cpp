// -----------------------------------------------------------------------------
//
// C9 - Drill 5
//
// Your check for a valid date may be very simple. Feel free to ignore leap years
// Don't accept a month that isn't [1,12] or day that isn't [1, 31]. test each
// with at least one invalid date.
//
// -----------------------------------------------------------------------------

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------

enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// -----------------------------------------------------------------------------

class Date
{
public:
    Date(int y, Month m, int d);

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

    Month month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }

private:
    int y, d;
    Month m;
};

// -----------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
{
    int yearMin(1900), yearMax(3000);
    if (yy > yearMax || yy < yearMin)
        cout << "Invalid year.";
    if (int(mm) > 12 || int(mm) < 1)		// you get a c cast
        cout << "Invalid month.";
    if (dd > 31 || dd < 1)
        cout << "Invalid day." << endl;
    else
    {
        y = yy; m = mm; d = dd;
    }
}

// -----------------------------------------------------------------------------

void Date::add_day(int n)
{
    //wrap days and months + increase year if necessary
    //you should see what I wrote the first time around...talk about nightmare code
    if (d += n > 31)
    {
        d = 1;
        int nextM = int(m) + 1;				// and you get a c cast
        if (nextM > 12)
        {
            add_month(1);
        }
        else
            m = Month(nextM);				//and you get a c cast
    }
}

// -----------------------------------------------------------------------------

void Date::add_month(int n)
{
    if (int nextM = int(m) + n > 12)		// and you get a c cast
    {
        m = Month::jan;
        add_year(1);
    }
    else
        m = Month(nextM);					//and you get a c cast
}

// -----------------------------------------------------------------------------

void Date::add_year(int n)
{
    y += n;
    if (y > 3000)
    {
        cout << "It is not the year 3000; busted" << endl;
        y -= n;
    }
}

// -----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << "(" << d.year()
        << "," << int(d.month())	// you all get c casts!
        << "," << d.day() << ")";
}

// -----------------------------------------------------------------------------

int main()
{
    //c casting...c casting everywhere!

    Date today( 1978, Month::dec, 31 );
    Date tomorrow( today );

    tomorrow.add_day(4);
    tomorrow.add_month(13);
    tomorrow.add_year(5);


    cout << today << endl;
    cout << tomorrow << endl;

    //invalid date
    Date invalidDate{ 1300, Month::dec, -4 };

    return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
