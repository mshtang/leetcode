def generateParenthesis(n):
    ans = []

    def backtrack(S='', left=0, right=0):
        if len(S) == 2 * n:
            print('1# if')
            ans.append(S)
            return
        if left < n:
            print('2# if')
            backtrack(S + '(', left + 1, right)
        if right < left:
            print('3# if')
            backtrack(S + ')', left, right + 1)

    backtrack()
    print(ans)


if __name__ == '__main__':
    generateParenthesis(2)
