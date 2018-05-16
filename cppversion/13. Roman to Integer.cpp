#include <iostream>
#include <string>
#include <unordered_map>

int toInteger(std::string s)
{
    std::unordered_map<char, int> T = {{'M', 1000},
                                       {'D', 500},
                                       {'C', 100},
                                       {'L', 50},
                                       {'X', 10},
                                       {'V', 5},
                                       {'I', 1}};
    int num = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (T[s[i]] < T[s[i + 1]])
            num -= T[s[i]];
        else
            num += T[s[i]];
    }
    return num + T[s[s.size() - 1]];
}

int main()
{
    std::cout << toInteger("MDCCLXXVI") << std::endl;
    std::cout << toInteger("MCMLIV") << std::endl;
    std::cin.get();
}