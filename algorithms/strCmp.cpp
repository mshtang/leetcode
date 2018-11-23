#include <iostream>

int strCmp(char *a, char *b)
{
    while (*a == *b)
    {
        if (*a == '\0')
            return 0;
        a++;
        b++;
    }
    if (*a > *b)
        return 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{

    char *a = "abcd";
    char *b = "abce";
    int res = 0;
    res = strCmp(a, b);
    std::cout << res << std::endl;
    return 0;
}
