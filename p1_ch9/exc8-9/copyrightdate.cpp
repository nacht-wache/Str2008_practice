#include "copyrightdate.h"
#include <string>
#include <stdexcept>

CopyrightDate::CopyrightDate(int inputYear, int inputMonth, int inputDay)
    :year(inputYear), month(inputMonth), day(inputDay)
{
    //simple check
    if(year < minYear || year > currentYear ||
            month < minMonth || month > maxMonth ||
            day < minDay || day > maxDay) throw std::out_of_range("copyright date");
    if(year == currentYear &&
            (month > currentMonth || day > currentDay))
        throw std::out_of_range("copyright date");
};

void CopyrightDate::readDate(int inputYear, int inputMonth, int inputDay)
{
    year = inputYear;
    month = inputMonth;
    day = inputDay;
}

std::ostream& operator<<(std::ostream& os, const CopyrightDate& outputCopyrightDate)
{
    return os << outputCopyrightDate.getYear() << '.'
              << outputCopyrightDate.getMonth() << '.'
              << outputCopyrightDate.getDay();
}

bool operator==(const CopyrightDate& firstCopyrightDate, const CopyrightDate& secondCopyrightDate)
{
    return firstCopyrightDate.getDay() == secondCopyrightDate.getDay() &&
            firstCopyrightDate.getMonth() == secondCopyrightDate.getMonth() &&
            firstCopyrightDate.getYear() == secondCopyrightDate.getYear();
}

bool operator!=(const CopyrightDate& firstCopyrightDate, const CopyrightDate& secondCopyrightDate)
{
    return !(firstCopyrightDate == secondCopyrightDate);
}
