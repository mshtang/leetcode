#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int closest3Sums(std::vector<int> nums, int target)
{
    std::sort(nums.begin(), nums.end());
    while (nums.size() <= 3)
    {
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
    int n = nums.size();
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int tmp = nums[i] + nums[j] + nums[k];
            if (abs(target - tmp) < abs(target - res))
            {
                res = tmp;
                if (res == target)
                    return res;
            }
            tmp > target ? k-- : j++;
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums{11, 22, 84, 74, 23, 789, 56, -19, -49, -227, -13};
    int target = 100;
    std::cout << closest3Sums(nums, target) << std::endl;
}