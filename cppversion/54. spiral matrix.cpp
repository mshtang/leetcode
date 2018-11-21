#include <iostream>
#include <vector>

std::vector<int> spiralMatrix(std::vector<std::vector<int>> &mat)
{
    if (mat.empty())
        return {};
    int l = 0, r = mat[0].size() - 1, u = 0, d = mat.size() - 1;
    std::vector<int> res;
    while (true)
    {
        // from left to right
        for (int col = l; col <= r; col++)
            res.push_back(mat[u][col]);
        if (++u > d)
            break;
        // from upside to down
        for (int row = u; row <= d; row++)
            res.push_back(mat[row][r]);
        if (--r < l)
            break;
        // from right to left
        for (int col = r; col >= l; col--)
            res.push_back(mat[d][col]);
        if (--d < u)
            break;
        // from down to upside
        for (int row = d; row >= u; row--)
            res.push_back(mat[row][l]);
        if (++l > r)
            break;
    }
    return res;
}

int main()
{
    std::vector<std::vector<int>> mat{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    std::vector<int> res;
    res = spiralMatrix(mat);
    for (auto ele : res)
        std::cout << ele << " ";
    std::cin.get();
}
