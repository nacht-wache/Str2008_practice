#ifndef ISBN_H
#define ISBN_H

#include <string>

class ISBN
{
public:
    ISBN() {};
    ~ISBN() {};

    ISBN(int inputFirstToken, int inputSecondToken, int inputThirdToken, std::string inputFourthToken);

    void readISBNTokens(int inputFirstToken, int inputSecondToken, int inputThirdToken, std::string inputFourthToken);

    int getFirstToken() const {return firstToken;};
    int getSecondToken() const {return secondToken;};
    int getThirdToken() const {return thirdToken;};
    std::string getFourthToken() const {return fourthToken;};
private:
    int firstToken;
    int secondToken;
    int thirdToken;
    std::string fourthToken; // digit or letter
};

std::ostream& operator<<(std::ostream& os, const ISBN& outputToken);

bool operator==(const ISBN& firstISBN, const ISBN& secondISBN);

bool operator!=(const ISBN& firstISBN, const ISBN& secondISBN);

#endif // ISBN_H
