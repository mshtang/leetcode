def isMatched(s):
    if len(s) % 2 != 0:
        return False
    stack = []
    par_dict = {'}': '{', ']': '[', ')': '('}
    for char in s:
        if char in par_dict.values():
            stack.append(char)
        elif char in par_dict.keys():
            if stack == [] or par_dict[char] != stack.pop():
                return False
        else:
            return False
    return stack == []


if __name__ == '__main__':
    print(isMatched('()()(){{{{[]}}}}'))
    print(isMatched('((())}'))
