import random


def bubble(nums):

    n = len(nums)

    for j in range(n):
        swapped = False
        for i in range(n - j - 1):
            if (nums[i] > nums[i + 1]):
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                swapped = True
        if swapped is False:
            break

    return nums


def selection(nums):

    n = len(nums)

    for i in range(n):
        tmp_min = nums[i]
        tmp_min_inx = i
        for j in range(i + 1, n):
            if (nums[j] < tmp_min):
                tmp_min = nums[j]
                tmp_min_inx = j
        nums[i], nums[tmp_min_inx] = nums[tmp_min_inx], nums[i]

    return nums


def insertion(nums):

    n = len(nums)

    for i in range(1, n):
        key = nums[i]
        j = i - 1
        while (key < nums[j] and j >= 0):
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = key

    return nums


def heapify(nums, n, i):
    largest = i
    l = i * 2 + 1
    r = i * 2 + 2
    if (l < n and nums[i] < nums[l]):
        # nums[i], nums[l] = nums[l], nums[i]
        largest = l
    if (r < n and nums[largest] < nums[r]):
        largest = r
    if largest != i:
        nums[largest], nums[i] = nums[i], nums[largest]
        heapify(nums, n, largest)
    return nums


def heapsort(nums):
    n = len(nums)
    for i in range(n, -1, -1):
        nums = heapify(nums, n, i)
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        nums = heapify(nums, i, 0)
    return nums


# def partition(nums):
#     random.shuffle(nums)
#     pivot = nums[0]
#     i = 1
#     j = len(nums)-1
#     while i<j:
#         while i<len(nums) and nums[i]>pivot:


def merge(nums, lo, mi, hi):

    i = lo
    j = mi + 1
    aux = nums[lo:hi + 1]
    for k in range(lo, hi):
        if i > mi:
            nums[k] = aux[j]
            j += 1
        elif j > hi:
            nums[k] = aux[i]
            i += 1
        elif aux[i] < aux[j]:
            nums[k] = aux[i]
            i += 1
        else:
            nums[k] = aux[j]
            j += 1

    # return nums


def mergesort_core(nums, lo, hi):
    if hi <= lo:
        return
    mi = lo + (hi - lo) // 2
    mergesort_core(nums, lo, mi)
    mergesort_core(nums, mi + 1, hi)
    merge(nums, lo, mi, hi)
    # return nums


def mergesort(nums):

    n = len(nums) - 1
    mergesort_core(nums, 0, n)
    # return nums


def main():
    nums = [6, 8, 3, 1, 0, 4, 2]
    mergesort(nums)
    print(nums)
    # print(bubble([1, 2, 3, 4, 5]))


if __name__ == '__main__':
    main()
