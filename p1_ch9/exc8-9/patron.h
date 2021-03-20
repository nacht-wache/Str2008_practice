#ifndef PATRON_H
#define PATRON_H

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


#include <iostream>

class Patron
{
public:
    Patron() {};
    ~Patron() {};

    Patron(std::string inputUserName, std::string inputUserSecondName, int inputCardNumber, double inputFee);

    void readUserName();
    void readCardNumber();
    void readFee();

    void setUserName(std::string inputUserName, std::string inputUserSecondName);
    void setCardNumber(int inputCardNumber);
    void setFee(double inputFee);

    std::string getUserName() const {return userFirstName + ' ' + userSecondName;};
    int getCardNumber() const {return  cardNumber;};
    double getFee() const {return  fee;};

    bool hasFee() {return fee;}; //false if 0, else true
private:
    std::string userFirstName;
    std::string userSecondName;
    int cardNumber;
    double fee;


};

std::ostream& operator<<(std::ostream& os, const Patron& outputPatron);

bool operator==(const Patron& firstPatron, const Patron& secondPatron);

bool operator!=(const Patron& firstPatron, const Patron& secondPatron);

#endif // PATRON_H
