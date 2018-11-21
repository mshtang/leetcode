#include <iostream>
#include <vector>

int maxSubarray(std::vector<int> &nums)
{
    int ans = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        ans = std::max(sum, ans);
        sum = std::max(sum, 0);
    }
    return ans;
}

int main()
{
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubarray(nums) << std::endl;
    std::cin.get();
}