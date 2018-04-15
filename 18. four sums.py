def fourSums(nums, target):
    n = len(nums)
    if n < 4:
        return 'no valid input'
    nums = sorted(nums)
    res = []
    for i in range(n-3):
        if (i > 1 and nums[i] == nums[i-1]):
            continue
        if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target):
            break
        if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target):
            continue
        for j in range(i+1, n-2):
            if(j > i+1 and nums[j] == nums[j-1]):
                continue
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target):
                break
            if(nums[i]+nums[j]+nums[n-1]+nums[n-2] < target):
                continue
            left = j+1
            right = n-1
            while(left < right):
                tmp = nums[i]+nums[j]+nums[left]+nums[right]
                if(tmp < target):
                    left += 1
                elif(tmp > target):
                    right -= 1
                else:
                    res.append((nums[i], nums[j], nums[left], nums[right]))
                    while True:
                        left += 1
                        if not (left < right and nums[left] == nums[left-1]):
                            break
                    while True:
                        right -= 1
                        if not (left < right and nums[right] == nums[right+1]):
                            break
    return res


print(fourSums([-5, 8, 12, 34, 76, -11, 23, -89, 100, 4, -24], 19))
