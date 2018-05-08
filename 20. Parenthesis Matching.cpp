#include <iostream>
#include <string>
#include <stack>

bool isMatched(std::string s)
{
    if (s.size() % 2 != 0)
        return false;
    std::stack<char> tmp;
    for (char &c : s)
    {
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            tmp.push(c);
            break;
        case ')':
            if (tmp.empty() || tmp.top() != '(')
                return false;
            else
                tmp.pop();
            break;
        case ']':
            if (tmp.empty() || tmp.top() != '[')
                return false;
            else
                tmp.pop();
            break;
        case '}':
            if (tmp.empty() || tmp.top() != '{')
                return false;
            else
                tmp.pop();
            break;
        default:;
        }
    }
    return tmp.empty();
}

int main()
{
    std::string s1 = "(){[[()]]}{}";
    std::string s2 = "[]((())}";
    std::cout << isMatched(s1) << std::endl;
    std::cout << isMatched(s2) << std::endl;
}