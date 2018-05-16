def closest3Sum(nums, target):
    nums = sorted(nums)
    res = nums[0]+nums[1]+nums[2]
    for i in range(len(nums)-2):
        j = i+1
        k = len(nums)-1
        while(j < k):
            sum = nums[i]+nums[j]+nums[k]
            if (abs(target-res) > abs(target-sum)):
                res = sum
                if(res == target):
                    return res
            if sum > target:
                k -= 1
            else:
                j += 1
    return res


if __name__ == '__main__':
    print(closest3Sum([11, 22, 84, 74, 23, 789, 56, -19, -49, -227, -13], 100))
