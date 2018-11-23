import random


def quickSort(nums):
    random.shuffle(nums)
    nums = sortCore(nums, 0, len(nums) - 1)
    return nums


def sortCore(nums, lo, hi):
    if (lo >= hi):
        return
    mi = partition(nums, lo, hi)
    nums = sortCore(nums, lo, mi - 1)
    nums = sortCore(nums, mi + 1, hi)
    return nums


def partition(nums, lo, hi):
    i = lo
    j = hi + 1
    pivot = nums[lo]
    while (True):
        while (pivot > nums[i]):
            i += 1
            if (i == hi):
                break
        while (pivot < nums[j]):
            j -= 1
            if (i >= j):
                break
        nums[i], nums[j] = nums[j], nums[i]
    nums[lo], nums[j] = nums[j], nums[lo]
    return j


def main():
    nums = quickSort([3, 5, 8, 7, 2, 9, 1, 10])
    print(nums)


if __name__ == '__main__':
    main()
