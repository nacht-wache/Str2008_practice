/*
 *
slightly modified version. allows a user to set amount of numbers in vector on his own.
 *
*/

#include <iostream>
#include <string>
#include <vector>

//const-by-reference. we don't want to change parameters.
void print(const std::string& label, const std::vector<int>& v)
{

    std::cout << label << '\n';

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << '\n';
    }
}

int main()
{

    std::cout << "please, set amount of numbres" << '\n';

    //variable to hold and write amount
    int users_input = 0;
    std::cin >> users_input;

    std::vector<int>numbers;
    for(int count = 0; count < (users_input+1); ++count)
        numbers.push_back(count);

    std::string label = "numbers 1 - " + std::to_string(users_input);

    print(label, numbers);
}
