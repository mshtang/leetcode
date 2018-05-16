#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> total;
    int n = nums.size();
    if (n < 4)
        return total;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            break;
        if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                break;
            if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                continue;
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                {
                    total.push_back(std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    do
                    {
                        left++;
                    } while (nums[left] == nums[left - 1] && left < right);
                    do
                    {
                        right--;
                    } while (nums[right] == nums[right + 1] && left < right);
                }
            }
        }
    }
    return total;
}

int main()
{
    std::vector<int> nums = {-5, 8, 12, 34, 76, -11, 23, -89, 100, 4, -24};
    int target = 19;
    std::vector<std::vector<int>> res;
    res = fourSum(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}