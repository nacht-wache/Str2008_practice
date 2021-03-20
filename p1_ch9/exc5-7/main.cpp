/*
EXERSICE 5

This exercise and the next few require you to design and implement a
Book class, such as you can imagine as part of software for a library.

Class Book should have members for:
1. ISBN,
2. title,
3. author,
4. copyright date.
5. store data on whether or not the book is checked out.

Create functions for:
1. returning those data values.
2. checking a book in and out.

Do simple validation of data entered into a Book;
for example, accept ISBNs only of the form n-n-n-x
where n is an integer and x is a digit or a letter.

*/

/*

EXERSICE 6

Add operators for the Book class. Have the == operator check whether
the ISBN numbers are the same for two books. Have != a1so compare
the ISBN numbers. Have a << print out the title author, and ISBN on
separate lines.

*/

/*

EXERSICE 7

Create an enumerated type for the Book class called Genre.
Have the types be fiction, nonfiction, periodica1, biography, children.
Give each book a Genre and make appropriate changes to the Book constructor
and member functions.

*/

#include <iostream>
#include "book.h"

int main()
{
    try {
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

        std::cout << nachtwache << example;

        nachtwache.modifyAvailability();

        std::cout <<nachtwache.getAvailability();

        if(nachtwache.getISBN() == example.getISBN())
            std::cout << "Books " << nachtwache.getTitle() << " and "
                      << example.getTitle() << " are equal" << std::endl;
        if(nachtwache.getISBN() != example.getISBN())
            std::cout << "Books " << nachtwache.getTitle() << " and "
                      << example.getTitle() << " are unequal" << std::endl;

    }  catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;

    }
    catch (std::runtime_error& e) {
        std::cout << "Runtime error: " << e.what() << std::endl;
    }
}
