def longestValidParentheses(s):
    n = len(s)
    longest = 0
    st = []
    for i in range(n):
        if s[i] == '(':
            st.append(i)
        else:
            if (len(st) != 0):
                if s[st[-1]] == '(':
                    st.pop()
                else:
                    st.append(i)
            else:
                st.append(i)

    if len(st) == 0:
        longest = n
    else:
        a = n
        b = 0
        while len(st) != 0:
            b = st[-1]
            st.pop()
            longest = max(longest, a - b - 1)
            a = b
        longest = max(longest, a)
    return longest


if __name__ == '__main__':
    print(longestValidParentheses('()(((())'))