#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int> nums, int target)
{
    std::vector<int> not_found = {-1, 1};
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            res.push_back(i);
            break;
        }
    }

    if (res.empty())
        return not_found;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == target)
        {
            res.push_back(i);
            break;
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 7, 8};
    int target = 3;
    std::vector<int> res;
    res = searchRange(nums, target);
    for (int i : res)
        std::cout << i << " ";
    std::cin.get();
}