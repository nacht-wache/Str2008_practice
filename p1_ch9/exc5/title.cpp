#include "title.h"
#include <string>
#include <iostream>

Title::Title(std::string inputTitle)
    :title(inputTitle) {};

void Title::readTitle(std::string inputTitle)
{
   title = inputTitle;
}

std::ostream& operator<<(std::ostream& os, const Title& outputTitle)
{
    return os << '"' << outputTitle.getTitle() << '"';
}
