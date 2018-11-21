#include <iostream>
#include <vector>

void permute(std::vector<int> &nums, int start, std::vector<std::vector<int>> &res)
{
    if (nums.size() <= start)
    {
        res.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        std::swap(nums[start], nums[i]);
        permute(nums, start + 1, res);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permutation2(std::vector<int> nums)
{
    std::vector<std::vector<int>> res;
    permute(nums, 0, res);
    return res;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<std::vector<int>> res;
    res = permutation2(nums);
    for (auto i : res)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}