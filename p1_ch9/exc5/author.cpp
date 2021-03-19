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
