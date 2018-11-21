def searchRotated(nums, target):
    lo = 0
    hi = len(nums) - 1
    while (lo < hi):
        mid = (lo + hi) // 2
        if (nums[mid] > nums[hi]):
            lo = mid + 1
        else:
            hi = mid

    rot = lo
    lo = 0
    hi = len(nums) - 1
    while (lo <= hi):
        mid = (lo + hi) // 2
        realmid = (mid + rot) % len(nums)
        if (nums[realmid] == target):
            return realmid
        if (nums[realmid] < target):
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


if __name__ == '__main__':
    print(searchRotated([4, 5, 6, 7, 0, 1, 2], 0))
