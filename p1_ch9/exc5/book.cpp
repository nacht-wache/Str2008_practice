#include "book.h"
#include "title.h"
#include "author.h"
#include "isbn.h"
#include "copyrightdate.h"
#include <iostream>

Book::Book(ISBN inputToken, Title inputTitle, Author inputName, CopyrightDate inputCopyrightDate)
    :token(inputToken), title(inputTitle), authorName(inputName), copyrightDate(inputCopyrightDate) {};

std::string Book::getAvailability() const {
    switch (availability) {
    case 'y':
        return "currenly is available.\n";
        break;
    case 'n':
        return "currently is not available.\n";
        break;
    default:
        throw std::out_of_range("unknown getAvailability error");
    }
}

void Book::modifyAvailability()
{
    if(availability == 'y') {
        availability = 'n';

    }
    else availability = 'y';

    std::cout << "The availability of the book with the title " << getTitle() << " has been modified" << std::endl;
}

void Book::readISBN()
{
    std::cout << "please, enter ISBN tokens each followed by newline.\n";
    int inputFirstToken, inputSecondToken, inputThirdToken;
    std::string inputFourthToken;
    std::cin >> inputFirstToken >> inputSecondToken >> inputThirdToken >> inputFourthToken;

    token.readISBNTokens(inputFirstToken, inputSecondToken, inputThirdToken, inputFourthToken);
}

void Book::readTitle()
{
    std::cout << "please, enter the title of the book followed by newline. Use '_' instead of whitespaces.\n";
    std::string inputTitle;
    std::cin >> inputTitle;

    title.readTitle(inputTitle);
}

void Book::readAuthor()
{
    std::cout << "please, enter the first and the second names of the author each followed by newline.\n";
    std::string inputFirstName, inputSecondName;
    std::cin >> inputFirstName >> inputSecondName;

    authorName.readAuthor(inputFirstName, inputSecondName);
}

void Book::readCopyrightDate()
{
    std::cout << "please, enter the year, month and day of copyright date of the book each followed by newline.\n";
    int inputYear, inputMonth, inputDay;
    std::cin >> inputYear >> inputMonth >> inputDay;

    copyrightDate.readDate(inputYear, inputMonth, inputDay);
}

void Book::readAvailability()
{
    std::cout << "wether book is available or not?" << std::endl
              << "y/n" << std::endl;
    char readAvailabilty;
    std::cin >> readAvailabilty;

    if(readAvailabilty != 'y' && readAvailabilty != 'n')
                throw std::runtime_error("wrong symbol on input.\n");

    availability = readAvailabilty;
}

void Book::setISBN(int setFirstToken, int setSecondToken, int setThirdToken, std::string setFourthToken)
{
    token.readISBNTokens(setFirstToken, setSecondToken, setThirdToken, setFourthToken);
}

void Book::setTitle(std::string setTitle)
{
    title.readTitle(setTitle);
}

void Book::setAuthor(std::string setFirstName, std::string setSecondName)
{
    authorName.readAuthor(setFirstName, setSecondName);
}

void Book::setCopyrightDate(int setYear, int setMonth, int setDay)
{
    copyrightDate.readDate(setYear, setMonth, setDay);
}

void Book::setAvailability(char setAvailability)
{
    switch(setAvailability) {
    case 'y':
        availability = setAvailability;
        break;
    case 'n':
        availability = setAvailability;
        break;
    default:
        throw std::runtime_error("wrong symbol on set");
    }
}

std::ostream& operator<<(std::ostream& os, const Book& outputBook)
{
    return os << "ISBN is:" << std::endl
              << outputBook.getISBN() << std::endl
              << "Title of the book is:" << std::endl
              << outputBook.getTitle() << std::endl
              << "Author of the book is:" << std::endl
              << outputBook.getAuthor() << std::endl
              << "Copyright date of the book is:" << std:: endl
              << outputBook.getCopyrightDate() <<std::endl
              << "Availabilty of the book is: " << std::endl
              << outputBook.getAvailability() <<std::endl;
}
