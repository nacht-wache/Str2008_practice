#include "isbn.h"
#include <stdexcept>
#include <iostream>

ISBN::ISBN(int inputFirstToken, int inputSecondToken, int inputThirdToken, std::string inputFourthToken)
    :firstToken(inputFirstToken), secondToken(inputSecondToken), thirdToken(inputThirdToken), fourthToken(inputFourthToken)
{
    if(inputFirstToken < 0 || inputFirstToken > 9
            || inputSecondToken < 0 || inputSecondToken > 9
            || inputThirdToken < 0 || inputThirdToken > 9
            || inputFourthToken.length() > 1 ) // accept only string with one sign (letter or digit)
        throw std::out_of_range("one or more ISBN tokens");
}

//redundunt to line 5?
void ISBN::readISBNTokens(int inputFirstToken, int inputSecondToken, int inputThirdToken, std::string inputFourthToken)
{
    if(inputFirstToken < 0 || inputFirstToken > 9
            || inputSecondToken < 0 || inputSecondToken > 9
            || inputThirdToken < 0 || inputThirdToken > 9
            || inputFourthToken.length() > 1 ) // accept only string with one sign (letter or digit)
        throw std::out_of_range("one or more ISBN tokens");

    firstToken = inputFirstToken;
    secondToken = inputSecondToken;
    thirdToken = inputThirdToken;
    fourthToken = inputFourthToken;
}


std::ostream& operator<<(std::ostream& os, const ISBN& outputToken)
{
    return os << outputToken.getFirstToken() << '-'
              << outputToken.getSecondToken() << '-'
              << outputToken.getThirdToken() << '-'
              << outputToken.getFourthToken();
}

bool operator==(const ISBN& firstISBN, const ISBN& secondISBN)
{
    return (firstISBN.getFirstToken() == secondISBN.getFirstToken()
            &&
            firstISBN.getSecondToken() == secondISBN.getSecondToken()
            &&
            firstISBN.getThirdToken() == secondISBN.getThirdToken()
            &&
            firstISBN.getFourthToken() == secondISBN.getFourthToken());
}

bool operator!=(const ISBN& firstISBN, const ISBN& secondISBN)
{
    return !(firstISBN == secondISBN);
}
