#include <iostream>

bool isPalindrome(int x);

int main()
{
    // int a, b, c;
    std::cout << "a=12345 is " << isPalindrome(12345);
    std::cout << "\na=12321 is " << isPalindrome(12321);
    std::cout << "\na=123321 is " << isPalindrome(123321);
    std::cin.get();
}

bool isPalindrome(int x)
{
    if (x < 0 || x % 10 == 0)
        return false;
    int res = 0;
    while (x > res)
    {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    return ((x == res) || (x == res / 10));
}