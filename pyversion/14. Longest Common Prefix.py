def commonPrefix(strs):
    '''
    param: strs (in) a list of strings
    param: prefix (out) a string representing the common prefix
    '''
    prefix = ''
    if len(strs) == 0:
        return prefix
    for j in range(len(strs)):
        for i in range(1, len(strs)):
            if len(strs[i]) < j:
                break
            if strs[i][j] != strs[0][j]:
                return prefix

        if (i+1) == len(strs):
            prefix += strs[0][j]
    return prefix


if __name__ == '__main__':
    print(commonPrefix(['leetcode', 'leetfeed', 'leeftode', 'leaft']))
