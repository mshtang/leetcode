def nextPermutation(nums):

    k = -1
    for i in range(len(nums) - 2, 0, -1):
        if nums[i] < nums[i + 1]:
            k = i
            break

    if k == -1:  # nums already in descending order
        nums = sorted(nums)
        return nums

    for i in range(len(nums) - 1, k, -1):
        if (nums[i] > nums[k]):
            nums[i], nums[k] = nums[k], nums[i]
            break

    nums[k + 1:] = sorted(nums[k + 1:])

    return nums


if __name__ == '__main__':
    print(nextPermutation([1, 5, 8, 4, 7, 6, 5, 3, 1]))
