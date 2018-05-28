def extreme_insertion_index(nums, target, from_left):
    lo = 0
    hi = len(nums)

    while lo < hi:
        mid = (lo + hi) // 2
        if (nums[mid] > target) or (from_left and target == nums[mid]):
            hi = mid
        else:
            lo = mid + 1
    return lo


def searchRange(nums, target):
    left_idx = extreme_insertion_index(nums, target, True)

    if left_idx == len(nums) or nums[left_idx] != target:
        return [-1, 1]

    return [left_idx, extreme_insertion_index(nums, target, False) - 1]


if __name__ == '__main__':
    print(searchRange([1, 2, 2, 2, 2, 5, 6], 2))
