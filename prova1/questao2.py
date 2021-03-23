def calc_max(arr, esq, dir):
    if dir == esq:
        return arr[esq]
    m = (esq + dir) // 2
    lado_esq = calc_max(arr, esq, m)
    lado_dir = calc_max(arr, m + 1, dir)
    if (lado_esq > lado_dir):
        return lado_esq

    return lado_dir


arr = [10, 2, 31, 4, 54, 3]
print(calc_max(arr, 0, 5))
