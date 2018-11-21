#include <iostream>
#include <string>

std::string multiply(std::string str1, std::string str2)
{
    int n1 = str1.size(), n2 = str2.size();
    std::string res(n1 + n2, '0');
    for (int i = n1 - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = n2 - 1; j >= 0; --j)
        {
            int tmp = (res[i + j + 1] - '0') + (str1[i] - '0') * (str2[j] - '0') + carry;
            res[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        res[i] += carry;
    }

    size_t startpos = res.find_first_not_of("0");
    if (std::string::npos != startpos)
    {
        return res.substr(startpos);
    }
    return "0";
}

int main()
{
    std::string str1 = "123", str2 = "456";
    std::string res;
    res = multiply(str1, str2);
    std::cout << res << std::endl;
    std::cin.get();
}