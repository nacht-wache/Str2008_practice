/*

Replace Name_pair: :print() with a (globa1) operator<<
and define == and != for Name_pairs.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>

class Name_pairs
{
public:

    Name_pairs() {};
    ~Name_pairs() {};

    void read_names();
    void read_ages();
    void sortByName();

    std::vector<std::string> getNames() const {return names;};
    std::vector<double> getAges() const {return ages;};
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
        for(int count {0}; count < names.size(); count++) {
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
        std::cout << names[count] << '\n';
        double age {0.0};
        std::cin >> age;

        if(age < 0 || age > 120) throw std::out_of_range("age: out of range");
        ages.push_back(age);
    }
}

std::ostream& operator<<(std::ostream& os, const Name_pairs& object)
{
    for(int count {0}; count < object.getNames().size(); count++) {
        os << "Name is: " << object.getNames()[count]
                  << ' '
                  << "Age is: " << object.getAges()[count] << '\n';

    }

    return os;
}

void Name_pairs::sortByName()
{
    std::vector<std::string> nameCopy = names;
    std::vector<double> ageCopy = ages;

    std::sort(names.begin(), names.end());

    for( int count {0}; count < names.size(); count++) {
        for( int countNext {0}; countNext < names.size(); countNext++) {
            if(names[count] == nameCopy[countNext]) {
                ages[count] = ageCopy[countNext];
            }
        }
    }

    std::cout << "\nsorted by names: Done!\n";
}

bool operator==(const Name_pairs& fstObject, const Name_pairs& secObject)
{
    if(fstObject.getNames().size() != secObject.getNames().size()
       ||
       fstObject.getAges().size() != secObject.getAges().size())
        return false;


    for(int count {0}; count < fstObject.getNames().size(); count++){
        if(fstObject.getNames()[count] != secObject.getNames()[count]
           ||
           fstObject.getAges()[count] != secObject.getAges()[count]){
            return false;
        }
    }
    return true;
}

bool operator!=(const Name_pairs& fstObject, const Name_pairs& secObject)
{
    return !(fstObject == secObject);
}

int main()
{
    try {
        Name_pairs first, second;

        std::cout << "First object.\n";
        first.read_names();
        first.read_ages();
        std::cout << first;

        first.sortByName();
        std::cout << first;

        std::cout << "Second object.\n";
        second.read_names();
        second.read_ages();
        std::cout << second;

        second.sortByName();
        std::cout << second;

        if(first == second){
            std::cout << "Objects are equal\n";
        }

        if(first != second){
            std::cout << "Objects are different\n";
        }

    }  catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
