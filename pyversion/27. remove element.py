def removeElement(nums, val):
    i = 0
    for j in range(len(nums)):
        if nums[j] != val:
            nums[i] = nums[j]
            i += 1
    return i


if __name__ == '__main__':
    res = removeElement([1, 2, 3, 2, 1, 5], 1)
    print(res)
