INT_MAX = 2e31 - 1
INT_MIN = -2e31


def divide(dividend, divisor):

    if ((not divisor) or (dividend == INT_MIN and divisor == -1)):
        return INT_MAX

    if ((dividend < 0) ^ (divisor < 0)):
        sign = -1
    else:
        sign = 1

    dvd = abs(dividend)
    dvs = abs(divisor)
    res = 0
    while (dvd >= dvs):
        temp = dvs
        multiple = 1
        while (dvd >= (temp << 1)):
            temp = temp << 1
            multiple = multiple << 1
        dvd -= temp
        res += multiple
    if sign == 1:
        return res
    else:
        return (-res)


if __name__ == '__main__':
    print(divide(15, 3))