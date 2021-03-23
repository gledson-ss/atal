def part(arr, esq, dir):
    x = arr[dir]
    index = esq
    for j in range(esq, dir):
        if arr[j] <= x:
            arr[index], arr[j] = arr[j], arr[index]
            index += 1

    arr[index], arr[dir] = arr[dir], arr[index]
    return index


def mediana(arr, esq, dir, k):

    if (k > 0 and k <= dir - esq + 1):
        index = part(arr, esq, dir)

        if(index - esq == k - 1):
            return arr[index]

        if (index - esq > k - 1):
            return mediana(arr, esq, index - 1, k)

        return mediana(arr, index + 1, dir, k - index + esq - 1)

    return 999999


def resposta(arr):
    esq = 0
    dir = len(arr) - 1

    tamanho = len(arr)
    k = 0
    if tamanho % 2 == 0:
        k = tamanho / 2
    else:
        k = (tamanho + 1) / 2

    return min(arr), mediana(arr, esq, dir, k), max(arr)


n = int(input())
arr = []
for i in range(0, n):
  arr.append(int(input()))

print(resposta(arr))
