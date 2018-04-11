def isPalindrome(x):
    if x < 0 or x % 10 == 0:
        return False
    res = 0
    while x > res:
        res = res * 10 + x % 10
        x = x // 10
    return ((res == x) or (res//10 == x))


if __name__ == '__main__':
    print('{} is {}'.format(13579, isPalindrome(13579)))
    print('{} is {}'.format(12321, isPalindrome(12321)))
    print('{} is {}'.format(128123321821, isPalindrome(128123321821)))
