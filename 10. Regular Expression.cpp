#include <iostream>
#include <string>

bool isMatch(std::string s, std::string p)
{
    if (p.empty())
        return s.empty();
    if (p[1] == '*')
        return isMatch(s, p.substr(2)) || !s.empty() &&
                                              (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p);
    else
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
               isMatch(s.substr(1), p.substr(1));
}

int main()
{
    std::string text = "abcd";
    std::string pattern = "a.b*cd";
    std::cout << isMatch(text, pattern) << std::endl;
    std::cin.get();
    return 0;
}