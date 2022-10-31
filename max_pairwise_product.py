def maximum_pairwise_product():
    n = int(input())
    a = [int(x) for x in input().split(' ')]
    assert(len(a) == n)

    max_index_1 = -1
    for i in range(0, len(a)):
        if max_index_1 == -1 or a[max_index_1] < a[i]:
            max_index_1 = i
    max_index_2 = -1
    for i in range(0, len(a)):
        if (max_index_2 == -1 or a[max_index_2] < a[i]) and (i != max_index_1):
            max_index_2 = i

    print(a[max_index_2] * a[max_index_1])


maximum_pairwise_product()
