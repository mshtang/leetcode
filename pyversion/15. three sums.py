def threeSums(num):
    '''
    param: num (in) a list of integer numbers
    param: list (out) a list of triplets that in each triplet the sum is 0
    '''
    num = sorted(num)
    res = []
    for i in range(len(num)):
        target = -num[i]
        if target < 0:
            break
        front = i+1
        back = len(num)-1
        while(front < back):
            complement = num[front]+num[back]
            if complement < target:
                front += 1
            elif complement > target:
                back -= 1
            else:
                a = num[i]
                b = num[front]
                c = num[back]
                res.append((a, b, c))
                while(front < back and num[front] == b):
                    front += 1
                while(front < back and num[back] == c):
                    back -= 1
        while(i+1 < len(num) and num[i+1] == num[i]):
            i += 1
    return res


if __name__ == '__main__':
    print(list(threeSums([1, 2, 3, 5, -1, -3, -2, -6])))
