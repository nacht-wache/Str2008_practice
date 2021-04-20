/*
Read five names into a vector<string> name, then prompt the user for the
ages of the people named and store the ages in a vector<double>age. Then
print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),
name.end())) and print out the (name[i],age[i]) pairs.

The tricky part here is to get the age vector in the correct order to match the sorted name vector.
Hint: Before sorting age, take a copy and use that to make a copy of age in the right order after sorting age.
Then, do that exercise again but allowing an arbitrary number of names.
*/


//initialize vector of names
//store user's input in vector of ages on the outputed names of people
//print out pair name[i], age[i]
//sort the names (sort(name.begin(), name.end()))
//print out the (name[i],age[i]) pairs


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string>Names;
std::vector<double>Age;

void CreateNameVector()
{
    std::string InputName = "S";
    std::cout << "please, enter the names. enter 'Q' to stop.\n";

    for(int count = 0; true; count++)
    {
        std::cin >> InputName;
        if(!(InputName == "Q")) Names.push_back(InputName);
        else break;
    }
}

void CreateAgeVector()
{
    double InputAge;
    std::cout << "please, enter the age of this persons.\n";

    for(int count = 0; count < Names.size(); count++)
    {
        std::cout << Names[count] << '\n';
        std::cin >> InputAge;
        Age.push_back(InputAge);
    }
}

void OutputNameAgePair()
{
    std::cout << '\n' << "Current name-age pairs are:\n";

    for(int count = 0; count < Names.size(); count++)
    {
        std::cout << Names[count] << ' ' << Age[count] << '\n';
    }
}

void SortTask()
{
    std::vector<std::string>NamesCopy = Names;
    std::vector<double>AgeCopy = Age;

    Age.clear();

    std::sort(Names.begin(), Names.end());

    for(int countNames = 0; countNames < Names.size(); countNames++)
    {
        for(int countCopy = 0; countCopy < NamesCopy.size(); countCopy++)
        {
            if(Names[countNames] == NamesCopy[countCopy])
                Age[countNames] = AgeCopy[countCopy];
        }
    }
}

int main()
{
    CreateNameVector();
    CreateAgeVector();
    OutputNameAgePair();
    SortTask();
    OutputNameAgePair();
    return 0;
}
