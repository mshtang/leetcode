def toRoman(x):
    base = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
    tens = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
    huns = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
    thou = ['', 'M', 'MM', 'MMM']
    # last digit
    last = x % 10
    roman4 = base[last]
    last = (x//10) % 10
    roman3 = tens[last]
    last = (x//100) % 10
    roman2 = huns[last]
    last = x//1000
    roman1 = thou[last]
    return roman1+roman2+roman3+roman4


if __name__ == '__main__':
    print(toRoman(1776))
    print(toRoman(1954))
    print(toRoman(2999))
    print(toRoman(1200))
