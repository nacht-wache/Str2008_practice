/*
 *
slightly modified version. allows a user to set amount of numbers in vector on his own.
 *
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::string;

//const reference can be initialized with rvalue
void print(const string& label, const vector<int>& vector) {
    cout << label << '\n';

    for (int count : vector) {
        cout << count << '\n';
    }
}

int main() {
    cout << "please, set amount of numbers (integer type)" << '\n';

    //variable to hold and write amount
    int users_input {0};
    std::cin >> users_input;

    std::vector<int>numbers;
    for(int count = 0; count < (users_input+1); ++count) {
        numbers.push_back(count);
    }

    string label = "numbers 1 - " + std::to_string(users_input);

    print(label, numbers);
}
