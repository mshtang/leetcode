def combinationSum(candidates, target):
    """
		:type candidates: List[int]
		:type target: int
		:rtype: List[List[int]]
		"""
    res = []

    def com(nums, target, i, cur):
        if i == len(nums):
            return
        if target == 0:
            res.append(list(cur))
            return
        if nums[i] <= target:
            cur.append(nums[i])
            com(nums, target - nums[i], i, cur)
            cur.pop()
            com(nums, target, i + 1, cur)
        else:
            com(nums, target, i + 1, cur)

    com(candidates, target, 0, [])
    return res


if __name__ == '__main__':
    res = combinationSum([2, 3, 6, 7], 7)
    print(res)