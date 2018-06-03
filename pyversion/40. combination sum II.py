def combiSum2(nums, target):
    nums.sort()
    res = []
    findCombi(nums, 0, [], res, target)
    return res


def findCombi(nums, start, path, res, target):

    if not target:
        res.append(path)
        return
    for i in range(start, len(nums)):
        if i > start and nums[i] == nums[i - 1]:
            continue
        if nums[i] > target:
            break
        findCombi(
            nums,
            i + 1,
            path + [nums[i]],
            res,
            target - nums[i],
        )


if __name__ == '__main__':
    print(combiSum2([10, 1, 2, 7, 6, 1, 5], 8))