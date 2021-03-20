#ifndef TITLE_H
#define TITLE_H

#include <string>

class Title
{
public:
    Title() {};
    ~Title() {};

    Title(std::string inputTitle);

    void readTitle(std::string inputTitle);

    std::string getTitle() const { return title;};
private:
    std::string title;
};

std::ostream& operator<<(std::ostream& os, const Title& outputTitle);

bool operator==(const Title& firstTitle, const Title& secondTitle);

bool operator!=(const Title& firstTitle, const Title& secondTitle);

#endif // TITLE_H
