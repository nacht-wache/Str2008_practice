#ifndef BOOK_H
#define BOOK_H

#include "isbn.h"
#include "author.h"
#include "title.h"
#include "copyrightdate.h"

class Book
{
public:
    Book() {};
    ~Book() {};

    Book(ISBN inputToken, Title inputTitle, Author inputName, CopyrightDate inputCopyrightDate);

    void readCopyrightDate();
    void readISBN();
    void readAuthor();
    void readTitle();
    void readAvailability();

    void setISBN(int setFirstToken, int setSecondToken, int setThirdToken, std::string setFourthToken);
    void setTitle(std::string setTitle);
    void setAuthor(std::string setFirstName, std::string setSecondName);
    void setCopyrightDate(int setYear, int setMonth, int setDay);
    void setAvailability(char setAvailability);

    void modifyAvailability();

    ISBN getISBN() const {return token;};
    Title getTitle() const {return title;};
    Author getAuthor() const {return authorName;};
    CopyrightDate getCopyrightDate() const {return copyrightDate;}
    std::string getAvailability() const;
private:
    ISBN token;
    Title title;
    Author authorName;
    CopyrightDate copyrightDate;
    char availability;
};

std::ostream& operator<<(std::ostream& os, const Book& outputBook);

#endif // BOOK_H
