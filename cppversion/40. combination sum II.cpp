#include <algorithm>
#include <iostream>
#include <vector>

void findCombi(std::vector<int> &nums, std::vector<int> &candidates, int target, int begin_index, std::vector<std::vector<int>> &res);

std::vector<std::vector<int>>
combiSum2(std::vector<int> &nums, int target)
{

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    std::vector<int> candidates;
    findCombi(nums, candidates, target, 0, res);
    return res;
}

void findCombi(std::vector<int> &nums, std::vector<int> &candidates, int target, int begin_index, std::vector<std::vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(candidates);
        return;
    }

    else
    {
        for (int i = begin_index; i < nums.size(); i++) // iterative
        {
            if (nums[i] > target)
                return;
            if ((nums[i] == nums[i - 1]) and (i > begin_index))
                continue; // check duplicate combinations
            candidates.push_back(nums[i]);
            findCombi(nums, candidates, target - nums[i], i + 1, res); // recursive
            candidates.pop_back();
        }
    }
}

int main()
{
    std::vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    int target = 9;
    std::vector<std::vector<int>> res;
    res = combiSum2(nums, target);
    for (auto values : res)
    {
        for (auto v : values)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}
