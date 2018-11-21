#include <iostream>
#include <string>

bool isMatched(std::string str, std::string pattern)
{
    int m = str.size(), n = pattern.size();
    int i = 0, j = 0, asterisk = -1, match;
    while (i < m)
    {
        if (j < n and pattern[j] == '*')
        {
            match = i;
            asterisk = j++;
        }
        else if (j < n and (str[i] == pattern[j] or pattern[j] == '?'))
        {
            i++;
            j++;
        }
        else if (asterisk > 0)
        {
            j = asterisk + 1;
            i = ++match;
        }
        else
            return false;
    }
    while (j < n and pattern[j] == '*')
        j++;
    return j == n;
}

int main()
{
    std::string str = "abed";
    std::string pattern = "?b*d**";
    std::cout << isMatched(str, pattern) << std::endl;
    std::cin.get();
}