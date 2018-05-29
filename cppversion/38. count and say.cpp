#include <iostream>
#include <string>

std::string countAndSay(int n)
{
    if (n == 0)
        return "";
    std::string res = "1";
    while (--n)
    {
        std::string cur = "";
        for (int i = 0; i < res.size(); i++)
        {
            int count = 1;

            while (i + 1 < res.size() && (res[i] == res[i + 1]))
            {
                count++;
                i++;
            }
            cur += std::to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}

int main()
{
    std::string res;
    res = countAndSay(10);
    std::cout << res << std::endl;
    std::cin.get();
}
