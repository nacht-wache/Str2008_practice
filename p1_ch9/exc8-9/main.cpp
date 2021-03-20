/*
 *
 *
EXERCISE 8

1. Create a Patron class for the library.
2. The class will have a user's name, library card number, and library fees (if owed).
3. Have functions that access these methods, as well as a function to set the fee of the user.
4. Have a helper method that returns a Boolean (bool)
depending on whether or not the user owes a fee

*/

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

#include <iostream>
#include "library.h"

int main()
{
    try {
        Library library;
        Patron yahor, verzila, Hegel;
        Book nachtwache, example;
        std::cout << "Die Nachtwache des Bonaventura.\n";

        nachtwache.readISBN();
        nachtwache.readTitle();
        nachtwache.readAuthor();
        nachtwache.readGenre();
        nachtwache.readCopyrightDate();
        nachtwache.readAvailability();

        example.setISBN(0,0,0,"d");
        example.setTitle("Example");
        example.setAuthor("Example", "author");
        example.setGenre(3);
        example.setCopyrightDate(1401,3,31);
        example.setAvailability('n');

        yahor.setCardNumber(34);
        yahor.setUserName("yahor", "amazing");
        yahor.setFee(0);

        verzila.setCardNumber(0);
        verzila.setUserName("verzila", "BANKI");
        verzila.setFee(34.54);

        Hegel.setCardNumber(666);
        Hegel.setUserName("Schelling", "One_love");
        Hegel.setFee(999999);

        library.checkOweFees();
        for(int count {0}; count < )
        std::cout << library.getOweFees();

        std::cout << nachtwache << example;

    }  catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << '\n';;

    }
    catch (std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << '\n';;
    }
}
