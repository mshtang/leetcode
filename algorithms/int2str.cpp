#include <iostream>

void int2str(int num, char *str)
{
    char buf[10] = "";
    //char ret[10];

    int tmp = num < 0 ? -num : num;
    int len = 0;
    if (str == NULL)
        return;

    while (tmp)
    {
        buf[len++] = tmp % 10 + '0';
        tmp /= 10;
    }
    int i = 0;
    if (num < 0)
    {
        str[0] = '-';
        i++;
    }

    while (len)
    {
        str[i] = buf[--len];
        i++;
    }
}

int main()
{
    int i = -345;
    char res[10];
    int2str(i, res);
    std::cout << res << std::endl;
    return 0;
}