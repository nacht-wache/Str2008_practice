/*

Write a function that takes a vector<String> argument and returns a
vector<int> containing the number of characters in each string. Also find
the longest and the shortest string and the lexicographically first and last
string. How many separate functions would you use for these tasks?
Why?

*/

#include <iostream>
#include <vector>
#include <string>

std::vector<int> numofchar(const std::vector<std::string>& stringvector)
{
    if(stringvector.size() == 0) throw std::runtime_error("empty vector");
    if(stringvector.size() == 1) throw std::runtime_error("vector of one element");

    std::vector<int> numofchar(stringvector.size());
    for(int count {0}; count < stringvector.size(); count++)
    {
        numofchar[count] = stringvector[count].length();
    }
    return numofchar;
}

int longest (const std::vector<std::string>& stringvector)
{
    if(stringvector.size() == 0) throw std::runtime_error("empty vector");
    if(stringvector.size() == 1) throw std::runtime_error("vector of one element");

    std::string longest {stringvector[0]};

    int indexlongest {0};

    for(int count {0}; count < stringvector.size(); count++)
    {
        if(longest.length() < stringvector[count].length())
        {
            longest = stringvector[count];
            indexlongest = count;
        }
    }
    return indexlongest;
}

int shortest (const std::vector<std::string>& stringvector)
{
    if(stringvector.size() == 0) throw std::runtime_error("empty vector");
    if(stringvector.size() == 1) throw std::runtime_error("vector of one element");

    std::string smallest {stringvector[0]};

    int indexsmallest {0};

    for(int count {0}; count < stringvector.size(); count++)
    {
        if(smallest.length() > stringvector[count].length())
        {
            smallest = stringvector[count];
            indexsmallest = count;
        }
    }

    return indexsmallest;
}

int first (const std::vector<std::string>& stringvector)
{
    if(stringvector.size() == 0) throw std::runtime_error("empty vector");
    if(stringvector.size() == 1) throw std::runtime_error("vector of one element");

    std::string First = stringvector[0];
    int indexfirst {0};

    for(int count {0}; count < stringvector.size(); count++)
    {
        if(stringvector[count] < First)
        {
            First = stringvector[count];
            indexfirst = count;
        }
    }
    return indexfirst;
}

int last (const std::vector<std::string>& stringvector)
{
    if(stringvector.size() == 0) throw std::runtime_error("empty vector");
    if(stringvector.size() == 1) throw std::runtime_error("vector of one element");

    std::string last = stringvector[0];
    int indexlast {0};

    for(int count {0}; count < stringvector.size(); count++)
    {
        if(stringvector[count] > last)
        {
            last = stringvector[count];
            indexlast = count;
        }
    }
    return indexlast;
}


int main()
{
    try {
        std::vector<std::string> stringvector{"yahor", "is", "my", "best", "friend"};

        for(int count {0}; count < numofchar(stringvector).size(); count++)
        {
            std::cout << "num of characters of " << count << " element is: " << numofchar(stringvector)[count] << '\n';
        }

        std::cout << "the longest is: " << stringvector[longest(stringvector)] << '\n'
                  << "the shortest is: " << stringvector[shortest(stringvector)] << '\n'
                  << "lexographically the first is: " << stringvector[first(stringvector)] << '\n'
                  << "lexographically the last is: " << stringvector[last(stringvector)] << '\n';
    }  catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
}

