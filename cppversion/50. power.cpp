#include <iostream>

double powern(double x, int n)
{
    if (n == 0)
        return 1;
    double t = powern(x, n / 2);
    if (n % 2)
        return n < 0 ? 1 / x * t * t : x * t * t;
    else
        return t * t;
}

double powern2(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = -n;
        x = 1 / x;
    }
    if (n % 2 == 0)
        return powern2(x * x, n / 2);
    else
        return powern2(x * x, n / 2) * x;
}

int main()
{
    std::cout << powern(2, 3) << std::endl;
    std::cout << powern2(2, 3) << std::endl;
    std::cin.get();
}