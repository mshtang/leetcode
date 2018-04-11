#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strings)
{
    std::string prefix = "";
    if (strings.size() == 0)
        return prefix;

    for (int i = 0; i < strings.size(); i++)
    {
        int j = 1;
        for (; j < strings.size() && strings[j].size() > i; j++)
        {
            if (strings[j][i] != strings[0][i])
                return prefix;
        }
        if (j == strings.size())
            prefix += strings[0][i];
    }
    return prefix;
}

int main()
{
    std::vector<std::string> lcp = {"Leetcode", "Leets", "Leet", "Leetf"};
    std::cout << "LCP: " << longestCommonPrefix(lcp);
}