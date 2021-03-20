#include "library.h"

/*
 *
6. Create functions to add books to the library, add patrons to the library, and check out books.
7. Whenever a user checks out a book,
have the library make sure that both the user and the book are in the library.
8. If they aren't, report an error.
9. Then check to make sure that the user owes no fees.
10. If the user does, report an error.
11. If not, create a Transaction, and place it in the vector of Transactions.
12. Also create a method that will return a vector that
contains the names of all Patrons who owe fees
*/

bool Library::hasBook(Book book)
{
    for(int count {0}; count < this->books.size(); count++)
        if(book == this->books[count]) return true;
    return false;

}
bool Library::hasPatron(Patron patron)
{
    for(int count {0}; count < this->patrons.size(); count++)
        if(patron == this->patrons[count]) return true;
    return false;

}

void Library::checkOutBook(Book book, Patron patron)
{
    if(!hasBook(book)) throw std::runtime_error("book is not in the library");
    if(!hasPatron(patron)) throw std::runtime_error("patron is not in the library");

    if(patron.hasFee()) throw std::runtime_error("user has a fee");

    Date date {2021, Date::mar, 20};
    Transaction createTr {book, patron, date};

    transaction.push_back(createTr);
}

void Library::checkOweFees()
{
    for(int count {0}; this->patrons.size(); count++)
    {
        if(this->patrons[count].hasFee()) oweFees.push_back(this->patrons[count]);
    }
}

Book Library::outputBooks() const
{
    for(int count {0}; count < this->books.size(); count++)

}

Patron Library::outputPatrons() const
{

}

Patron Library::outputOweFees() const
{

}

std::ostream& operator<<(std::ostream& os, const Library& outputLibrary)
{
    return os <<
}
