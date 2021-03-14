/*Write a program that plays the game "Rock, Paper, Scissors." If you are
not familiar with the game do some research (e.g., on the web using
Google). Research is a common task for programmers. Use a switch statement to solve this exercise. Also, the machine should give random
answers (i.e., select the next rock, paper, or scissors randomly) . Real randonmess is too hard to provide just now, 
so just build a vector with a sequence of values to be used as "the next value." If you build the vector
into the program, it will always play the same game, so maybe you
should let the user enter some values. Try variations to make it less easy
for the user to guess which move the machine will make next.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    vector<string>opps {"Rock, Paper, Scissors"};
    vector<char>indecies {'0', '1', '2', '0', '1', '2', '2', '1', '0', '2', '0', '1', '2', '2', '2', '1'};
    char index;
    int i = 0;
    while (index = indecies[i]){
    switch (index)
    {
    case '0':
        cout << indecies [0] << '\t';
        ++i;
        index = indecies[i];
        switch (index)
        {
            case '1':
            cout << indecies [1] << '\t' << "Paper wins Rock.\n";
            break;
        
            case '2':
            cout << indecies [2] << '\t' << "Rock wins Scissors.\n";
            break;
        }
        break;
    
    case '1':
        cout << indecies [1] << '\t';
        ++i;
        index = indecies[i];
        switch (index)
        {
            case '0':
            cout << indecies [0] << '\t' << "Paper wins Rock.\n";
            break;
        
            case '2':
            cout << indecies [2] << '\t' << "Scissors wins Paper.\n";
            break;
        }
        break;
    
    case '2':
        cout << indecies [1] << '\t';
        ++i;
        index = indecies[i];
        switch (index)
        {
            case '0':
            cout << indecies [0] << '\t' << "Scissors wins Paper.\n";
            break;
        
            case '2':
            cout << indecies [2] << '\t' << "Rock wins Scissors.\n";
            break;
        }
        break;
    
    default:
        break;
    }
    }
}