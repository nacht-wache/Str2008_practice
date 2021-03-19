/*

A Name_pairs class holding (name,age) pairs
where name is a string and age is a double.

Represent that as a vector<String> (called name)
and a vector<double> (called age) member.

Provide an input operation read_names() that reads a series of names.
Provide a read_ages() operation that prompts the user for an age for each name.
Provide a print() operation that prints out the (name[i],age[i]) pairs
(one per line) in the order determined by the name vector.
Provide a sort() operation that sorts the name vector in a1phabetical order and reorganizes
the age vector to match. Implement all "operations" as member functions.
Test the class (of course : test early and often).

*/

#include <iostream>
#include <vector>
#include <algorithm>

class Name_pairs
{
public:

    Name_pairs() {};
    ~Name_pairs() {};

    void read_names();
    void read_ages();
    void print();
    void sortByName();
private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

void Name_pairs::read_names()
{
    std::cout << "Please, enter a list of names. Enter 'Q' to stop.\n";
    std::string name;

    while(std::cin >> name && name != "Q")
    {
        for(int count {0}; count < names.size(); count++)
        {
            if(name == names[count]) throw std::runtime_error("error: the same name entered twice");
        }

        names.push_back(name);

        //don't know how to test onto digits in string type

    }
}

void Name_pairs::read_ages()
{
    std::cout << "Please, enter the age of the names below.\n";

    for(int count {0}; count < names.size(); count++)
    {
        std::cout << names[count] << std::endl;
        double age {0.0};
        std::cin >> age;

        if(age < 0 || age > 120) throw std::out_of_range("age: out of range");
        ages.push_back(age);
    }
}

void Name_pairs::print()
{
    std::cout << std::endl;

    for(int count {0}; count < names.size(); count++)
    {
        std::cout << "Name is: " << names[count] << " and age is: " << ages[count] << std::endl;
    }
}

void Name_pairs::sortByName()
{
    std::vector<std::string> nameCopy = names;
    std::vector<double> ageCopy = ages;

    std::sort(names.begin(), names.end());

    for( int count {0}; count < names.size(); count++)
    {
        for( int countNext {0}; countNext < names.size(); countNext++)
        {
            if(names[count] == nameCopy[countNext])
            {
                ages[count] = ageCopy[countNext];
            }
        }
    }

    std::cout << std::endl << "sorted by names: Done!\n";
}

int main()
{
    try {
        Name_pairs example;

        example.read_names();
        example.read_ages();
        example.print();

        example.sortByName();
        example.print();

    }  catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
