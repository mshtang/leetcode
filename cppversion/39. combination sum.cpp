#include <algorithm>
#include <iostream>
#include <vector>

void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &res, std::vector<int> &combination, int begin)
{
    if (!target)
    {
        res.push_back(combination);
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; i++)
    {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], res, combination, i);
        combination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
}

int main()
{
    std::vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> res;
    res = combinationSum(candidates, target);
    for (auto values : res)
    {
        for (auto value : values)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cin.get();
}