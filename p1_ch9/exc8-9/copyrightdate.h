#ifndef COPYRIGHTDATE_H
#define COPYRIGHTDATE_H

#include <string>
#include <iostream>

class CopyrightDate
{
public:
    CopyrightDate() {};
    ~CopyrightDate() {};

    CopyrightDate(int inputYear, int inputMonth, int inputDay);

    void readDate(int inputYear, int inputMonth, int inputDay);

    int getYear() const {return year;};
    int getMonth() const {return month;};
    int getDay() const {return day;};
private:
    int year;
    int month;
    int day;
    int currentYear = 2021;
    int currentMonth = 3;
    int currentDay = 18;
    const int minYear = 1400;
    const int minMonth = 1;
    const int maxMonth = 12;
    const int minDay = 1;
    const int maxDay = 31;
};

std::ostream& operator<<(std::ostream& os, const CopyrightDate& outputCopyrightDate);

bool operator==(const CopyrightDate& firstCopyrightDate, const CopyrightDate& secondCopyrightDate);

bool operator!=(const CopyrightDate& firstCopyrightDate, const CopyrightDate& secondCopyrightDate);

#endif // COPYRIGHTDATE_H
