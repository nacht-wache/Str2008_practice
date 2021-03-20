#ifndef LIBRARY_H
#define LIBRARY_H


/*
EXERCISE 9

1. Create a Library class.
2. Include vectors of Books and Patrons.
3. Include a struct called Transaction.
4. Have it include a Book, a Patron, and a Date from the chapter.
5. Make a vector of Transactions.
6. Create functions to add books to the library, add patrons to the library, anci check out books.
7. Whenever a user checks out a book,
have the library make sure that both the user and the book are in the library.
8. If they aren't, report an error.
9. Then check to make sure that the user owes no fees.
10. If the user does, report an error.
11. If not, create a Transaction, and place it in the vector of Transactions.
12. Also create a method that will return a vector that
contains the names ofall Patrons who owe fees
*/

class Library
{
public:
    Library();
};

#endif // LIBRARY_H
