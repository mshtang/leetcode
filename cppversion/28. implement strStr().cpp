#include <string>
#include <iostream>

int strStr(std::string haystack, std::string needle)
{
    if (!needle.length())
        return 0;
    for (int i = 0; i < (haystack.length() - needle.length() + 1); i++)
    {
        int j = 0;
        for (; j < needle.length(); j++)
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == needle.length())
            return i;
    }
    return -1;
}

int main()
{
    std::string haystack = "thisismyworldisaidno";
    std::string needle = "ismy";
    int res = 0;
    res = strStr(haystack, needle);
    std::cout << res << std::endl;
    std::cin.get();
}