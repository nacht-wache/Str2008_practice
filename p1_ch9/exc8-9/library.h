#ifndef LIBRARY_H
#define LIBRARY_H


/*
EXERCISE 9

1. Create a Library class.
2. Include vectors of Books and Patrons.
3. Include a struct called Transaction.
4. Have it include a Book, a Patron, and a Date from the chapter.
5. Make a vector of Transactions.
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

#include "book.h"
#include "patron.h"
#include "date.h"
#include "transaction.cpp"
#include <iostream>
#include <vector>

class Library
{
public:
    Library() {};
    ~Library() {};

    Library(std::vector<Book> books, std::vector<Patron> patrons)
        :books(books), patrons(patrons) {};

    std::vector<Transaction> transaction;

    void checkOutBook(Book book, Patron patron);
    void checkOweFees();

    bool hasBook(Book book);
    bool hasPatron(Patron patron);

    void addBook(Book book) {books.push_back(book);};
    void addPatron(Patron patron) {patrons.push_back(patron);};

    std::vector<Patron> getOweFees() const {return oweFees;};
    std::vector<Book> getBooks() const {return books;};
    std::vector<Patron> getPatrons() const {return patrons;};

    Book outputBooks() const;
    Patron outputPatrons() const;
    Patron outputOweFees() const;
private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Patron> oweFees;
};

std::ostream& operator<<(std::ostream& os, const Library& outputLibrary);

#endif // LIBRARY_H
