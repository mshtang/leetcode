def countAndSay(n):
    if n == 0:
        return ''
    res = '1'
    n = n - 1
    while (n):
        cur = ''
        i = 0
        while (i < len(res)):
            count = 1
            while (i + 1 < len(res) and res[i] == res[i + 1]):
                count += 1
                i += 1
            cur = cur + str(count) + res[i]
            i += 1
        res = cur
        n -= 1
    return res


if __name__ == '__main__':
    print(countAndSay(5))