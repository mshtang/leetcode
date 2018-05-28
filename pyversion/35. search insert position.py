def searchInsert(nums, target):
    lo = 0
    hi = len(nums) - 1
    while lo <= hi:
        mi = lo + (hi - lo) // 2
        if nums[mi] > target:
            hi = mi - 1
        else:
            lo = mi + 1

    return lo


if __name__ == '__main__':
    nums = [2, 5, 9, 11]
    # print(searchInsert(nums, 1))
    print(searchInsert(nums, 7))
    # print(searchInsert(nums, 15))
