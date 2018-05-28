#include <iostream>
#include <vector>

int searchInsert(std::vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mi = lo + (hi - lo) / 2;
        if (nums[mi] < target)
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    return lo;
}

int main()
{
    std::vector<int> nums = {1, 3, 5, 8, 9};
    std::cout << searchInsert(nums, 10) << std::endl;
    std::cout << searchInsert(nums, 0) << std::endl;
    std::cout << searchInsert(nums, 7) << std::endl;
    std::cin.get();
}
