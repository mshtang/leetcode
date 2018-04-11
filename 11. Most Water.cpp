#include <iostream>
#include <vector>
#include <algorithm>

int mostWater(std::vector<int> &y)
{
    int i = 0;
    int j = y.size() - 1;
    int area = 0;
    while (i <= j)
    {
        area = std::max(area, (j - i) * std::min(y[i], y[j]));
        if (y[i] <= y[j])
            i++;
        else
            j--;
    }
    return area;
}

int main()
{
    int y_ints[] = {1, 3, 5, 8, 9, 10, 2, 7};
    // use an array to construt a vector
    std::vector<int> y(y_ints, y_ints + sizeof(y_ints) / sizeof(int));
    int area = 0;
    area = mostWater(y);
    std::cout << area << std::endl;
    std::cin.get();
    return 0;
}