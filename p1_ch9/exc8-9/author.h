#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Author
{
public:
    Author() {};
    ~Author() {};

    Author(std::string inputFirstName, std::string inputSecondName);

    void readAuthor(std::string inputFirstName, std::string inputSecondName);

    std::string getFirstName() const {return firstName;};
    std::string getSecondName() const {return secondName;};
private:
    std::string firstName;
    std::string secondName;
};

std::ostream& operator<<(std::ostream& os, const Author& outputAuthor);

bool operator==(const Author& firstAuthor, const Author& secondAuthor);

bool operator!=(const Author& firstAuthor, const Author& secondAuthor);

#endif // AUTHOR_H
