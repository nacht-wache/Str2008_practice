#include "author.h"
#include <string>
#include <iostream>

Author::Author(std::string inputFirstName, std::string inputSecondName)
    :firstName(inputFirstName), secondName(inputSecondName) {};


void Author::readAuthor(std::string inputFirstName, std::string inputSecondName)
{
    firstName = inputFirstName;
    secondName = inputSecondName;
}

std::ostream& operator<<(std::ostream& os, const Author& outputAuthor)
{
    return os << outputAuthor.getFirstName() << ' '
              << outputAuthor.getSecondName();
}

std::ostream& operator<<(std::ostream& os, const Author& outputAuthor);

bool operator==(const Author& firstAuthor, const Author& secondAuthor)
{
    return firstAuthor.getFirstName() == secondAuthor.getFirstName() &&
            firstAuthor.getSecondName() == secondAuthor.getSecondName();
}

bool operator!=(const Author& firstAuthor, const Author& secondAuthor)
{
    return !(firstAuthor == secondAuthor);
}
