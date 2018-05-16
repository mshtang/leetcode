def toRoman(roman):
    table = {'M': 1000,
             'D': 500,
             'C': 100,
             'L': 50,
             'X': 10,
             'V': 5,
             'I': 1}
    num = 0
    i = 0
    for i in range(len(roman)-1):
        if table[roman[i]] < table[roman[i+1]]:
            num -= table[roman[i]]
        else:
            num += table[roman[i]]

    return (num + table[roman[-1]])


if __name__ == '__main__':
    print(toRoman('MCMLIV'))
