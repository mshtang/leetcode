#include <iostream>
#include <vector>

int searchRotated(std::vector<int> nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    int rot = lo;
    lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int realmid = (mid + rot) % nums.size();
        if (nums[realmid] == target)
            return realmid;
        if (nums[realmid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main()
{
    std::vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    std::cout << searchRotated(a, 0) << std::endl;
    std::cin.get();
}