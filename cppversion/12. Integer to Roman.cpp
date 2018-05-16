#include <iostream>
#include <string>

std::string toRoman(int num)
{
    static const struct
    {
        int value;
        const char *roman;
    } table[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    std::string res;
    for (const auto &item : table)
    {
        if (num == 0)
            break;
        while (item.value <= num)
        {
            res += item.roman;
            num -= item.value;
        }
    }
    return res;
}

int main()
{
    int a = 1776;
    int b = 1954;
    int c = 1990;
    std::cout << toRoman(a) << std::endl;
    std::cout << toRoman(b) << std::endl;
    std::cout << toRoman(c) << std::endl;
    std::cin.get();
}