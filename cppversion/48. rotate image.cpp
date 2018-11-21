#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> &img)
{
    int n = img.size();
    //std::reverse(img.begin(), img.end());
    for (int i = 0; i < n / 2; ++i)
    {
        std::swap(img[i], img[n - i - 1]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < img[i].size(); ++j)
        {
            std::swap(img[i][j], img[j][i]);
        }
    }
    return img;
}

int main()
{
    std::vector<std::vector<int>> img{{1, 2, 3, 7}, {4, 5, 6, 5}, {7, 9, 0, 3}, {7, 4, 2, 1}};
    std::vector<std::vector<int>> res;
    res = rotate(img);
    for (auto i : img)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}