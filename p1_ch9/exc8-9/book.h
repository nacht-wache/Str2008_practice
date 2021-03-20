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

    enum Genre {
        fiction, nonfiction, periodical, biography, children
    };

    Book(ISBN inputToken, Title inputTitle, Author inputName, Genre inputGenre, CopyrightDate inputCopyrightDate);

    void readISBN();
    void readTitle();
    void readAuthor();
    void readGenre();
    void readCopyrightDate();
    void readAvailability();

    void setISBN(int setFirstToken, int setSecondToken, int setThirdToken, std::string setFourthToken);
    void setTitle(std::string setTitle);
    void setAuthor(std::string setFirstName, std::string setSecondName);
    void setGenre(int);
    void setCopyrightDate(int setYear, int setMonth, int setDay);
    void setAvailability(char setAvailability);

    void modifyAvailability();

    ISBN getISBN() const {return token;};
    Title getTitle() const {return title;};
    Author getAuthor() const {return authorName;};
    std::string getGenre() const;
    CopyrightDate getCopyrightDate() const {return copyrightDate;}
    std::string getAvailability() const;
private:
    ISBN token;
    Title title;
    Author authorName;
    Genre genre;
    CopyrightDate copyrightDate;
    char availability;
};

std::ostream& operator<<(std::ostream& os, const Book& outputBook);

#endif // BOOK_H
