def mostWater(y):
    i = 0
    j = len(y)-1
    max_area = 0
    while i <= j:
        area = (j-i)*min(y[i], y[j])
        if area > max_area:
            max_area = area
        if y[i] <= y[j]:
            i += 1
        else:
            j -= 1
    return max_area


if __name__ == '__main__':
    y = [1, 3, 5, 8, 9, 10, 2, 7]
    print(mostWater(y))
