#include "patron.h"
#include <iostream>

Patron::Patron(std::string inputUserFirstName, std::string inputUserSecondName, int inputCardNumber, double inputFee)
    :userFirstName(inputUserFirstName), userSecondName(inputUserSecondName),cardNumber(inputCardNumber), fee(inputFee)
{
    if(inputCardNumber < 0) throw std::out_of_range("negative card number");
    if(inputCardNumber > 100000) throw std::out_of_range("our library is not that big");

    if(fee < 0) throw std::out_of_range("negative fee");

};

void Patron::readUserName()
{
    std::cout << "please, enter the first and the second names of the user each followe by the newline.\n";
    std::string inputUserFirstName, inputUserSecondName;
    std::cin >> inputUserFirstName >> inputUserSecondName;

    //using set?
    userFirstName = inputUserFirstName;
    userSecondName = userSecondName;
};

void Patron::readCardNumber()
{
    std::cout << "please, enter the user's card number[0 to 10000].\n";
    int inputCardNumber;
    std::cin >> inputCardNumber;

    cardNumber = inputCardNumber;
};

void Patron::readFee()
{
    std::cout << "please, enter the fee. enter '0' if he/she has none.\n";
    int inputFee;
    std::cin >> inputFee;

    fee = inputFee;
};

std::ostream& operator<<(std::ostream& os, const Patron& outputPatron)
{
    return os << "User's name is: " << '\n'
              << outputPatron.getUserName() << '\n'
              << "User's card number is: " << '\n'
              << outputPatron.getCardNumber() << '\n'
              << "User's fee is: " << '\n'
              << outputPatron.getFee() << '\n';
}
