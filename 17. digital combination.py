def digitalCombinations(digits):
    kv = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
    if len(digits) < 0:
        return ''
    res = ['']
    for i in range(len(digits)):
        num = ord(digits[i])-ord('0')
        if (num < 0 or num > 9):
            break
        candidate = kv[num]
        if not candidate:
            continue
        tmp = ''
        for j in range(len(candidate)):
            for k in range(0, len(res)):
                tmp += (res[k]+candidate[j])
        res = tmp

    return res


if __name__ == '__main__':
    print(digitalCombinations('135'))
