Inf = 999999


def MatrixChainOrder(p, i, j):

    if i == j:
        return 0
    _min = Inf
    for k in range(i, j):

        count = (MatrixChainOrder(p, i, k)
                 + MatrixChainOrder(p, k + 1, j)
                 + p[i-1] * p[k] * p[j])

        if count < _min:
            _min = count

    return _min


arr = [10, 20, 30, 40, 30]
n = len(arr)

print("Minimum number of multiplications is ", MatrixChainOrder(arr, 1, n-1))
