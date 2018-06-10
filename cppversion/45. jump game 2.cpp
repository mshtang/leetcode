#include <iostream>
#include <vector>

int jump(std::vector<int> &nums)
{
    int n = nums.size(), step = 0, start = 0, end = 0;
    while (end < n - 1)
    {
        step++;
        int maxend = end + 1;
        for (int i = start; i <= end; i++)
        {
            if (i + nums[i] >= n - 1)
                return step;
            maxend = std::max(maxend, i + nums[i]);
        }
        start = end + 1;
        end = maxend;
    }
    return step;
}

int main()
{
    std::vector<int> nums{2, 1, 1, 2, 3, 1, 1, 3};
    std::cout << jump(nums) << std::endl;
    std::cin.get();
}
