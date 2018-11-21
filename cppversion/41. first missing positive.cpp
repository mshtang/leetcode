#include <iostream>
#include <utility>
#include <vector>

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            std::swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main()
{
    //std::vector<int> nums1 = {1, 2, 0};
    std::vector<int> nums2 = {6, 3, 4, 1, 8, 2};
    //std::cout << firstMissingPositive(nums1) << std::endl;
    int res = firstMissingPositive(nums2);
    std::cout << res << std::endl;
    std::cin.get();
}