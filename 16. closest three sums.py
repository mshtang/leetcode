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


if __name__ == '__main__':
    print(closest3Sum([-2, -1, 0, 1, 7, 19, 23, -47, 10], 15))
