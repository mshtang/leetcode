#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> digtialCombinations(std::string digits)
{
    static const std::vector<std::string> v = {"", "", "abc", "def",
                                               "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digits.empty())
        return std::vector<std::string>();
    std::vector<std::string> res = {""};
    for (int i = 0; i < digits.size(); ++i)
    {
        int num = digits[i] - '0';
        if (num < 0 || num > 9)
            break;
        const std::string &candidate = v[num];
        if (candidate.empty())
            continue;
        std::vector<std::string> tmp;
        for (int j = 0; j < candidate.size(); ++j)
        {
            for (int k = 0; k < res.size(); ++k)
            {
                tmp.push_back(res[k] + candidate[j]);
            }
        }
        res.swap(tmp);
    }
    return res;
}

int main()
{
    std::string digits = "231";
    std::vector<std::string> res;
    res = digtialCombinations(digits);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j];
        }
        std::cout << std::endl;
    }
}