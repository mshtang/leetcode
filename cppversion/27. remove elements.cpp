#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main()
{
    std::vector<int> nums = {5, 7, 2, 3, 4, 2, 1, 2, 1};
    int val = 2;
    int res = 0;
    res = removeElement(nums, val);
    std::cout << res << std::endl;
    std::cin.get();
}