/*
Improve print_until_s() from §8.5.2. Test it. What makes a good set of
test cases? Give reasons. Then, write a print_until_ss() that prints until it
sees a second occurrence of its quit argument.
*/

#include <vector>
#include <iostream>

void print_until_s(const std::vector<std::string>& v, const std::string& quit)
{
    if(v.size() == 0) std::runtime_error("empty vector used");
                                                                                    //unsigned int range is [0; 4 294 967 295]
    for(int count = 0; count < v.size(); count++) //              vector<string> max_size = 576 460 752 303 423 487;
    {                                                            //unsigned long long range is [0; 18 446 744 073 709 551 615]
        if(v[count] == quit) return;
        std::cout << v[count] << '\n';
    }
}

void print_until_ss(const std::vector<std::string>& v, const std::string& quit)
{
    if(v.size() == 0) std::runtime_error("empty vector used");

    for(int count = 0; count < v.size(); count++)
    {
        int quitCount {0};

        if(v[count] == quit) ++quitCount;
        if(quitCount == 2) return;

        std::cout << v[count] << '\n';
    }
}

int main()
{

}
