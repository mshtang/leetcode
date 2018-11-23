import sys
import collections
for line in sys.stdin:
    a = line.split()


def calc(a):
    res, a = term_value(a)
    if (len(a) == 0):
        return res, a
    boo = True
    i = 0
    while (len(a) > 0 and boo):
        if (a[i] == '+'):
            a = a[1:]
            res, a = term_value(a)
            res += res
        elif (a[i] == '-'):
            a = a[1:]
            res, a = term_value(a)
            res -= res
        elif (a[i] == ')'):
            a = a[1:]
        else:
            boo = False
    return res, a


def term_value(a):
    if (len(a) == 1):
        return int(a), ''
    res, a = factor_value(a)
    boo = False
    i = 0
    while (len(a) > 0 and boo):
        if (a[i] == "*"):
            a = a[1:]
            res = factor_value(a)[0] * res
            a = factor_value(a)[1]
        elif (a[i] == '/'):
            a = a[1:]
            res = res / factor_value(a)[0]
            a = factor_value(a)[1]
        else:
            boo = False
    return res, a


def factor_value(a):
    if (a[0] == '('):
        a = a[1:]
        return calc(a)
    else:
        s = 0
        i = 1
        while (i < len(a) and a[i].isdigit()):
            s = s * 10 + int(a[i])
            a = a[1:]
    return s, a


if __name__ == '__main__':
    res = calc('2+(3-5)**2')
    print(res)
